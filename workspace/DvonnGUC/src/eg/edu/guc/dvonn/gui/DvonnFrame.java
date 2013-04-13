package eg.edu.guc.dvonn.gui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;

import java.awt.Point;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Calendar;
import java.util.Stack;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.KeyStroke;
import javax.swing.SpringLayout;

import eg.edu.guc.dvonn.engine.Board;
import eg.edu.guc.dvonn.engine.Ring;

@SuppressWarnings("serial")
public class DvonnFrame extends JFrame implements ActionListener {
	Board board;
	Player player1, player2;

	public final static int WIDTH = 70;

	JPanel jplMain, jplPlayers, jplStatus;
	JScrollPane jplGame;
	JLabel jlblStatus, jlblPlayers, jlblPl1, jlblPl2, jlblN1, jlblN2, bkglbl,
			jlblDlgPl1, jlblDlgPl2;
	JLabel[] dvonnlbl = new JLabel[3];
	JTextField jtxtPl1, jtxtPl2, jtxtR, jtxtC;
	JButton selectedRingBtn = null, jbtnOk, jbtnCancel;
	RingButton[][] ringButtons;
	BufferedImage ringImg = null, ringSelImg = null, bkg = null;
	static Font f1 = new Font("Times New Roman", Font.PLAIN, 20);
	static Font f2 = new Font("Times New Roman", Font.BOLD, 22);

	JMenu file, help;
	JMenuBar menuBar;
	JMenuItem newGame, undo, exit;
	JRadioButton placeRings, randomGame, player, easyAI;
	ButtonGroup groupRadios, groupRadios2;
	JDialog jdlgNewGame;

	private int countDvonn;
	private boolean isRingSelected;
	private Point selectedRing;
	private Dimension area;
	private boolean needPaint;
	private Stack<Board> history;

	public static void main(String[] args) {
		new DvonnFrame();
	}

	public DvonnFrame() {

		// Main Panel
		jplMain = new JPanel();
		jplMain.setLayout(new BoxLayout(jplMain, BoxLayout.PAGE_AXIS));
		jplMain.setOpaque(true);
		setContentPane(jplMain);

		// Game Panel
		jplGame = new JScrollPane();
		jplGame.setLayout(null);
		jplGame.setOpaque(true);

		// Add Board Image
		try {
			bkg = ImageIO.read(new File("bkg2.jpg"));
		} catch (IOException e) {
		}
		if (bkg != null) {
			bkglbl = new JLabel(new ImageIcon(bkg));
			bkglbl.setBounds(0, 0, bkg.getWidth(), bkg.getHeight());
			jplGame.add(bkglbl);
		}

		jplMain.add(jplGame);

		// MENU
		// Set MenuBar
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);

		// File Menu
		file = new JMenu("File");
		file.setMnemonic(KeyEvent.VK_F);
		menuBar.add(file);
		// New Game
		newGame = new JMenuItem("New Game...");
		newGame.addActionListener(this);
		newGame.setActionCommand("newGame");
		newGame.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N,
				ActionEvent.CTRL_MASK));
		newGame.getAccessibleContext().setAccessibleDescription(
				"Starts a new Game.");
		file.add(newGame);
		file.addSeparator();
		// Exit
		exit = new JMenuItem("Exit", KeyEvent.VK_E);
		exit.setActionCommand("exit");
		exit.addActionListener(this);
		exit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_X,
				ActionEvent.ALT_MASK));
		exit.getAccessibleContext().setAccessibleDescription("Exits Game.");
		file.add(exit);

		// Undo Menu
		undo = new JMenuItem("Undo", KeyEvent.VK_E);
		undo.setActionCommand("undo");
		undo.addActionListener(this);
		undo.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Z,
				ActionEvent.CTRL_MASK));
		undo.getAccessibleContext().setAccessibleDescription("Undo.");
		menuBar.add(undo);

		// Setting the Frame
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Dvonn");
		if (bkg != null) {
			setSize(bkg.getWidth(), bkg.getHeight() + 50);
		}else{
			setSize(300,300);
		}
		setResizable(false);
		setLocation(200, 10);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		String cmd = e.getActionCommand();
		if (cmd.contains(",")) {
			int i = -1, j = -1;
			try {
				String[] p = cmd.split(",");
				i = Integer.parseInt(p[0]);
				j = Integer.parseInt(p[1]);
			} catch (Exception ee) {
			}
			if (i < board.rows && j < board.columns) {
				if (board.getCurrentPhase() == 0) {
					put(i, j);
				} else {
					if (!isRingSelected || selectedRing.equals(new Point(i, j))) {
						if (board.getTurn() == board.getColor(i, j)) {
							if (board.canMove(i, j)) {
								if (board.hasMoves(i, j)) {
									selectRing(i, j);
								} else {
									jlblStatus
											.setText("This ring got no moves!");
								}
							} else {
								jlblStatus
										.setText("Can't Move a Fully Surrounded Ring!");
							}
						} else {
							jlblStatus
									.setText("You can only move your pieces!");
						}
					} else {
						if (!moveTo(i, j)) {
							jlblStatus.setText("Illegal Move!");
						}
					}
					checkEnd();
				}
				return;
			}
		}
		if ("exit".equals(cmd)) {
			System.exit(0);
		} else if ("undo".equals(cmd)) {
			undo();
		} else if ("newGame".equals(cmd)) {
			newGameDialog();
		} else if ("ok".equals(cmd)) {
			if (newGame()) {
				jdlgNewGame.setVisible(false);
			}
		} else if ("cancel".equals(cmd)) {
			jdlgNewGame.setVisible(false);
		}
	}

	public void newGameDialog() {
		jdlgNewGame = new JDialog(this, "New Game");
		jdlgNewGame.setBounds(this.getBounds().x + 50, this.getBounds().y + 50,
				500, 450);
		jdlgNewGame.setResizable(false);

		jtxtPl1 = new JTextField("Player1");
		jtxtPl2 = new JTextField("Player2");
		jtxtR = new JTextField("5");
		jtxtC = new JTextField("11");
		jbtnOk = new JButton("Ok");
		jbtnCancel = new JButton("Cancel");
		jbtnOk.addActionListener(this);
		jbtnOk.setActionCommand("ok");
		jbtnCancel.addActionListener(this);
		jbtnCancel.setActionCommand("cancel");

		placeRings = new JRadioButton("Place all rings manually");
		placeRings.setSelected(true);
		randomGame = new JRadioButton("Start a random game");
		groupRadios = new ButtonGroup();
		groupRadios.add(placeRings);
		groupRadios.add(randomGame);

		player = new JRadioButton("Player");
		player.setSelected(true);
		easyAI = new JRadioButton("Easy AI");
		groupRadios2 = new ButtonGroup();
		groupRadios2.add(player);
		groupRadios2.add(easyAI);

		Object[] array = { "Player 1 name:", jtxtPl1, "Player 2 name:",
				jtxtPl2, " ", "No. of Rows:", jtxtR, "No. of Columns:",
				jtxtC, " ", placeRings, randomGame, " ",
				"Choose type of player:", player, easyAI };
		Object[] options = { jbtnOk, jbtnCancel };
		JOptionPane optionPane = new JOptionPane(array, -1,
				JOptionPane.YES_NO_OPTION, null, options, options[0]);

		jdlgNewGame.setContentPane(optionPane);
		jdlgNewGame.setVisible(true);
	}

	public boolean newGame() {
		int x, y;
		try {
			x = Integer.parseInt(jtxtR.getText());
			y = Integer.parseInt(jtxtC.getText());
		} catch (NumberFormatException e) {
			x = 5;
			y = 11;
		}
		if (x * y < 5) {
			JOptionPane.showMessageDialog(this, "Invalid Board Size!");
			return false;
		}
		if (easyAI.isSelected()) {
			board = new Board(x, y, 0);
		} else {
			board = new Board(x, y);
		}
		ringButtons = new RingButton[board.rows][board.columns];
		history = new Stack<Board>();

		setWindow();

		try {
			if (placeRings.isSelected()) {
				newNormalGame();
			} else if (randomGame.isSelected()) {
				newRandGame();
			}
			return true;
		} catch (IOException e) {
		}
		return false;
	}

	public void newRandGame() throws IOException {
		board.fillRandom();
		paintRings();
		paintAll(getGraphics());
		if (board.isEasyAI()) {
			easyAIPlay();
		}
		paintRings();
		needPaint = true;
		history.push(board.clone());
		getContentPane().validate();
		getContentPane().repaint();
	}

	public void newNormalGame() throws IOException {
		for (int i = 0; i < board.rows; i++) {
			for (int j = 0; j < board.columns; j++) {
				if (board.isEvenBoard() && i == board.rows - 1
						&& j == board.columns - 1) {
					continue;
				}
				ringButtons[i][j] = new RingButton();
				ringButtons[i][j].setBounds(j * WIDTH, i * WIDTH, WIDTH, WIDTH);
				ringButtons[i][j].addActionListener(this);
				ringButtons[i][j].setActionCommand(i + "," + j);
				jplGame.add(ringButtons[i][j]);
				jplGame.setComponentZOrder(ringButtons[i][j], 0);
			}
		}
		needPaint = true;
		history.push(board.clone());
		getContentPane().validate();
		getContentPane().repaint();
	}

	public void setWindow() {
		jplMain.removeAll();
		jplGame.removeAll();
		player1 = new Player(jtxtPl1.getText(), 1);
		if (board.isEasyAI()) {
			player2 = new Player("Easy Computer", 2);
		} else {
			player2 = new Player(jtxtPl2.getText(), 2);
		}

		paintBoard();
		paintPlayers();

		// Status Label
		jplStatus = new JPanel();
		jlblStatus = new JLabel("Welcome To Dvonn Game!");
		jlblStatus.setFont(f1);
		jlblStatus.setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY));
		jplStatus.setBackground(new Color(13468991));
		jplStatus.add(jlblStatus);
		jplMain.add(jplStatus);

		switchTurn();

		setSize(WIDTH * 11 + 11, WIDTH * 5 + 230);

		getContentPane().validate();
		getContentPane().repaint();
	}

	public void paintBoard() {
		for (int i = 0; i < board.rows; i++) {
			for (int j = 0; j < board.columns; j++) {
				if (board.isEvenBoard() && i == board.rows - 1
						&& j == board.columns - 1) {
					continue;
				}
				JLabel boardcell = null;
				try {
					BufferedImage img;
					if (i % 2 == j % 2) {
						img = ImageIO.read(new File("lightCell.png"));
					} else {
						img = ImageIO.read(new File("darkCell.png"));
					}
					boardcell = new JLabel(new ImageIcon(img));
				} catch (IOException e) {
				}
				boardcell.setBounds(WIDTH * j, WIDTH * i, WIDTH, WIDTH);
				jplGame.add(boardcell);
				jplGame.setComponentZOrder(boardcell, 0);
			}
		}

		area = new Dimension(WIDTH * board.columns, WIDTH * board.rows);
		jplGame.setPreferredSize(area);
		JScrollPane scroller = new JScrollPane(jplGame);
		scroller.setPreferredSize(new Dimension(WIDTH * 11, WIDTH * 5 + 5));

		jplGame.revalidate();
		jplGame.repaint();
		jplMain.add(scroller);

		getContentPane().validate();
		getContentPane().repaint();
	}

	public void paintPlayers() {
		jplPlayers = new JPanel();
		SpringLayout sLayout = new SpringLayout();
		jplPlayers.setLayout(sLayout);
		jlblPlayers = new JLabel("Players");
		jlblPlayers.setFont(new Font("Times New Roman", Font.BOLD, 30));
		jlblPlayers.setForeground(Color.GREEN.darker());

		jlblPl1 = new JLabel("White: ");
		jlblPl1.setFont(f1);
		jlblPl2 = new JLabel("Black: ");
		jlblPl2.setFont(f1);
		jlblN1 = new JLabel(player1.getName());
		jlblN1.setFont(f1);
		jlblN2 = new JLabel(player2.getName());
		jlblN2.setFont(f1);

		jplPlayers.add(jlblPlayers);
		jplPlayers.add(jlblPl1);
		jplPlayers.add(jlblPl2);
		jplPlayers.add(jlblN1);
		jplPlayers.add(jlblN2);

		sLayout.putConstraint(SpringLayout.WEST, jlblPlayers, 60,
				SpringLayout.WEST, jplPlayers);
		sLayout.putConstraint(SpringLayout.NORTH, jlblPlayers, 10,
				SpringLayout.NORTH, jplPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblPl1, 50,
				SpringLayout.WEST, jplPlayers);
		sLayout.putConstraint(SpringLayout.NORTH, jlblPl1, 50,
				SpringLayout.NORTH, jlblPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblPl2, 300,
				SpringLayout.WEST, jplPlayers);
		sLayout.putConstraint(SpringLayout.NORTH, jlblPl2, 50,
				SpringLayout.NORTH, jlblPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblN1, 100,
				SpringLayout.WEST, jlblPl1);
		sLayout.putConstraint(SpringLayout.NORTH, jlblN1, 50,
				SpringLayout.NORTH, jlblPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblN2, 100,
				SpringLayout.WEST, jlblPl2);
		sLayout.putConstraint(SpringLayout.NORTH, jlblN2, 50,
				SpringLayout.NORTH, jlblPlayers);

		jplMain.add(jplPlayers);
	}

	@SuppressWarnings("static-access")
	public void paintRings() {
		for (int i = 0; i < dvonnlbl.length; i++) {
			try {
				jplGame.remove(dvonnlbl[i]);
			} catch (Exception ee) {
			}
		}
		countDvonn = 0;
		for (int i = 0; i < board.rows; i++) {
			for (int j = 0; j < board.columns; j++) {
				try {
					if (ringButtons[i][j].getIcon() != null) {
						jplGame.remove(ringButtons[i][j]);
					}
				} catch (Exception e) {
				}
			}
		}
		for (int i = 0; i < board.rows; i++) {
			for (int j = 0; j < board.columns; j++) {
				if (board.isEvenBoard() && i == board.rows - 1
						&& j == board.columns - 1) {
					continue;
				}
				if (board.isEmpty(i, j)) {
					continue;
				}
				ringImg = board.getCell(i, j).cell.peek().img;
				ringSelImg = board.getCell(i, j).cell.peek().selectedImg;

				if (board.getColor(i, j) != board.DVONN) {
					ringButtons[i][j] = new RingButton(new ImageIcon(ringImg),
							new ImageIcon(ringSelImg), board.getColor(i, j));
				} else {
					ringButtons[i][j] = new RingButton(new ImageIcon(ringImg),
							null, board.getColor(i, j));
				}

				ringButtons[i][j].setBounds(WIDTH * j + 6, WIDTH * i + 6,
						ringImg.getWidth(), ringImg.getHeight());
				ringButtons[i][j].addActionListener(this);
				ringButtons[i][j].setActionCommand(i + "," + j);
				jplGame.add(ringButtons[i][j]);
				jplGame.setComponentZOrder(ringButtons[i][j], 0);
				if (board.getHeight(i, j) > 1) {
					ringButtons[i][j].setText(board.getHeight(i, j) + "");
				}
				if (ringButtons[i][j] != null && needPaint && board.isEasyAI()) {
					ringButtons[i][j].paint(ringButtons[i][j].getGraphics());
				}
				if (board.getColor(i, j) != board.DVONN && board.hasRed(i, j)) {
					ringImg = Ring.dvonn;
					dvonnlbl[countDvonn] = new JLabel(new ImageIcon(ringImg));
					dvonnlbl[countDvonn].setBounds(
							ringButtons[i][j].getBounds().x + 2,
							ringButtons[i][j].getBounds().y + 4,
							ringImg.getWidth(), ringImg.getHeight());
					jplGame.add(dvonnlbl[countDvonn]);
					jplGame.setComponentZOrder(dvonnlbl[countDvonn], 1);
					countDvonn++;
				}
			}
		}
		getContentPane().validate();
		getContentPane().repaint();
	}

	public void put(int i, int j) {
		if (board.put(i, j)) {
			switchTurn();
			paintRings();
			if (board.isEasyAI()) {
				easyAIPlay();
			}
			history.push(board.clone());
		}
	}

	public void selectRing(int i, int j) {
		if (board.getColor(i, j) != board.getTurn()) {
			return;
		}
		ringButtons[i][j].setSelected(!ringButtons[i][j].isSelected());
		isRingSelected = ringButtons[i][j].isSelected();
		selectedRing = new Point(i, j);
	}

	public boolean moveTo(int i, int j) {
		if (!isRingSelected || board.isGameOver()) {
			return false;
		}
		if (board.move(selectedRing.x, selectedRing.y, i, j)) {
			isRingSelected = false;
			switchTurn();
			paintRings();
			if (board.isEasyAI()) {
				easyAIPlay();
			}
			history.push(board.clone());
			return true;
		}
		return false;
	}

	public void easyAIPlay() {
		if (board.getTurn() != Board.PLAYER2) {
			return;
		}
		board.easyAIPlay();
		Calendar c = Calendar.getInstance();
		while (true) {
			Calendar c2 = Calendar.getInstance();
			if (c2.get(Calendar.SECOND) - c.get(Calendar.SECOND) >= 1) {
				break;
			}
		}
		paintRings();
		switchTurn();
	}

	public void checkEnd() {
		if (board.isGameOver()) {
			int winner = board.getWinner();
			switch (winner) {
			case 0:
				jlblStatus.setText("DRAW!!");
				jlblPlayers.setText("DRAW!!");
				JOptionPane.showMessageDialog(this, "DRAW!!");
				break;

			case 1:
				jlblStatus.setText(player1.getName() + " won!");
				jlblPlayers.setText(player1.getName() + " won!");
				JOptionPane.showMessageDialog(this, player1.getName() + " won!");
				break;

			case 2:
				jlblStatus.setText(player2.getName() + " won!");
				jlblPlayers.setText(player2.getName() + " won!");
				JOptionPane.showMessageDialog(this, player2.getName() + " won!");
				break;

			default:
				jlblStatus.setText("ERROR CALCULATING SCORE!");
			}
		}
		getContentPane().validate();
		getContentPane().repaint();
	}

	public void switchTurn() {
		if (board.getTurn() == Board.PLAYER1) {
			jlblStatus.setText(player1.getName() + "'s Turn");
			jlblPl1.setForeground(Color.RED);
			jlblPl1.setFont(f2);
			jlblPl2.setForeground(Color.BLACK);
			jlblPl2.setFont(f1);
			jlblN1.setForeground(Color.RED);
			jlblN1.setFont(f2);
			jlblN2.setForeground(Color.BLACK);
			jlblN2.setFont(f1);
		} else if (board.getTurn() == Board.PLAYER2) {
			jlblStatus.setText(player2.getName() + "'s Turn");
			jlblPl1.setForeground(Color.BLACK);
			jlblPl1.setFont(f1);
			jlblPl2.setForeground(Color.RED);
			jlblPl2.setFont(f2);
			jlblN1.setForeground(Color.BLACK);
			jlblN1.setFont(f1);
			jlblN2.setForeground(Color.RED);
			jlblN2.setFont(f2);
		}
		getContentPane().validate();
		getContentPane().repaint();
	}

	private void undo() {
		if (history != null && !history.isEmpty()) {
			board = (Board) (history.pop().clone());
		}
		paintRings();
		switchTurn();
	}

}