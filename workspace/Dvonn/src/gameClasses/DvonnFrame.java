package gameClasses;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.KeyEvent;

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
import javax.swing.JTextField;
import javax.swing.KeyStroke;
import javax.swing.SpringLayout;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;



@SuppressWarnings("serial")
public class DvonnFrame extends JFrame implements ActionListener{
	
	
	//Components Initialization
	private Game game;
		
	JPanel jplMain,jplGame,jplPlayers,jplStatus;
	JLabel jlblStatus,jlblPlayers,jlblPl1,jlblPl2,jlblN1,jlblN2,bkglbl,jlblDlgPl1,jlblDlgPl2;
	JLabel[] dvonnlbl = new JLabel[3];
	JTextField jtxtPl1,jtxtPl2;
	JMenu file,help;
	JMenuBar menuBar;
	JMenuItem newGame,exit;
	JRadioButton placeRings,randomGame;
	ButtonGroup groupRadios;
	JDialog jdlgNewGame;
	ringButton[][] ringButtons= new ringButton[11][5];
	JButton selectedRingBtn=null, jbtnOk ,jbtnCancel;
	Point selectedRing=null;
	BufferedImage ringImg=null,ringSelImg =null, bkg = null;
	Boolean ringSelected=false;
	Font f1 = new Font("Times New Roman",Font.PLAIN,20);
	Font f2 = new Font("Times New Roman",Font.BOLD,22);
	int ringsPlacedNum;
	
	public DvonnFrame(Game g)throws IOException{
		game = g;
		Jbinit();
	}
	
	public void Jbinit() throws IOException{
	
	//Panels
		jplMain = new JPanel();
		jplMain.setLayout(new BoxLayout(jplMain,BoxLayout.PAGE_AXIS));
		jplMain.setOpaque(true);
		getContentPane().add(jplMain);
		
		
		//Game Panel
		jplGame = new JPanel();
		jplGame.setLayout(null);
		jplGame.setOpaque(true);
		//Add Board Image
		try{
			bkg = ImageIO.read(new File("C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\board2.png"));
		}
		catch(IOException e){}
		if(bkg!=null){
			bkglbl  = new JLabel(new ImageIcon(bkg));
			bkglbl.setBounds(0,0,bkg.getWidth(),bkg.getHeight());
			jplGame.add(bkglbl);
			jplGame.setComponentZOrder(bkglbl,0);
		}
		jplGame.setPreferredSize(new Dimension(bkg.getWidth(),bkg.getHeight()));
		jplMain.add(jplGame);
		
		
		//Players Panel
		jplPlayers = new JPanel();
		jplMain.add(jplPlayers);
		
		//Status Label
		jplStatus = new JPanel();
		jplMain.add(jplStatus);
		
		jlblStatus = new JLabel("Welcome To Dvonn Game!");
		jlblStatus.setFont(f1);
		jlblStatus.setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY));
		jplStatus.setBackground(Color.GRAY);
		jplStatus.add(jlblStatus);
		
		
		
		
	//MENU
		//Set MenuBar
		
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		//File Menu
		file = new JMenu("File");
		file.setMnemonic(KeyEvent.VK_F);
		menuBar.add(file);
		//New Game
		newGame = new JMenuItem("New Game...",KeyEvent.VK_N) ;
		newGame.addActionListener(this);
		newGame.setActionCommand("newGame");
		newGame.setAccelerator(KeyStroke.getKeyStroke(
		        KeyEvent.VK_N, ActionEvent.CTRL_MASK));
		newGame.getAccessibleContext().setAccessibleDescription("Starts a new Game.");
		file.add(newGame);
		file.addSeparator();
		//Exit
		exit = new JMenuItem("Exit",KeyEvent.VK_E) ;
		exit.setActionCommand("exit");
		exit.addActionListener(this);
		exit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_X, ActionEvent.ALT_MASK));
		exit.getAccessibleContext().setAccessibleDescription("Exits Game.");
		file.add(exit);
		//Help Menu
		help = new JMenu("Help");
		help.setMnemonic(KeyEvent.VK_H);
		menuBar.add(help);
				
		
		
	//Setting Window
		setIconImage((new ImageIcon("images/icon.ico")).getImage());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Dvonn");
		setSize(bkg.getWidth()+6,700);
		setResizable(false);
		setLocation(200, 10);
		setVisible(true);
	}
	
	public void switchPlayerTurn(int player){
		if(player==3){
			game.playerTurn=Game.DVONN;
			jlblStatus.setText("Place a DVONN!");
			jlblPl1.setForeground(Color.BLACK);
			jlblPl1.setFont(f1);
			jlblPl2.setForeground(Color.BLACK);
			jlblPl2.setFont(f1);
			jlblN1.setForeground(Color.BLACK);
			jlblN1.setFont(f1);
			jlblN2.setForeground(Color.BLACK);
			jlblN2.setFont(f1);
			return;
		}
		if(game.playerTurn==Game.PLAYER2||game.playerTurn==Game.DVONN||player==Game.PLAYER1){
			game.playerTurn=Game.PLAYER1;
			jlblStatus.setText(game.p1.getName()+"'s Turn");
			jlblPl1.setForeground(Color.RED);
			jlblPl1.setFont(f2);
			jlblPl2.setForeground(Color.BLACK);
			jlblPl2.setFont(f1);
			jlblN1.setForeground(Color.RED);
			jlblN1.setFont(f2);
			jlblN2.setForeground(Color.BLACK);
			jlblN2.setFont(f1);
		}else if(game.playerTurn==Game.PLAYER1){
			game.playerTurn=Game.PLAYER2;
			jlblStatus.setText(game.p2.getName()+"'s Turn");
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
	
	public void setStackHeights(){
		for(int i=0; i<11; i++){
			for(int j=0; j<5; j++){
				if(game.board.cells[i][j].valid){
					if(game.board.cells[i][j].cell.size()>1) ringButtons[i][j].setText(game.board.cells[i][j].cell.size()+"");
				}
			}
		}
	}
	
	public void movePile(String actionCmd,JButton ringBtn){
		if(ringBtn==selectedRingBtn){
			ringButtons[selectedRing.x][selectedRing.y].setSelected(false);
			ringSelected=false;
					
		}else{
			Point fromRing = (Point)selectedRing.clone();
			ringSelected=false;
			setSelectedRing(actionCmd);
			Point toRing = (Point)selectedRing.clone();
			
			Move m = new Move(fromRing,toRing,game);
			if(m.doMove()){
				ringSelected=false;
				game.board.cells[fromRing.x][fromRing.y].blanked=true;
				
				clearInvalid();
				paintRings();
				setStackHeights();
				switchPlayerTurn(0);
				checkEnd();
				if(!game.board.canPlayerMove())	switchPlayerTurn(0);
				checkEnd();
			}else{
				jlblStatus.setText("Illegel Move!");
				ringSelected=true;	
				selectedRing = (Point)fromRing.clone();
			}
			
			
		}
		
//		Move m = new Move(new Point(selectedRing.x,selectedRing.y),null,game);
//		Point[] moves = m.validMovesNoBlanked(); 
//		for(int i=0;i<moves.length;i++){
//			ringButtons[moves[i].x][moves[i].y].setSelected(false);
//		}
		
		getContentPane().validate();
		getContentPane().repaint();
	}
	
	
	
	public void setSelectedRing(String actionCmd){
		if(ringSelected) return;
		int x ,y;
		if(actionCmd.length()<3){	
			x = Integer.parseInt(actionCmd.charAt(0)+"");
			y = Integer.parseInt(actionCmd.charAt(1)+"");
		}else{
			x = Integer.parseInt(actionCmd.substring(0,2));
			y = Integer.parseInt(actionCmd.charAt(2)+"");
		}
		selectedRing = new Point(x,y);
	}
	
	public void selectRing(){
		int p=game.board.cells[selectedRing.x][selectedRing.y].cell.peek().getPlayer();
		if(p==game.playerTurn){
			if(!game.board.canMove(new Point(selectedRing.x,selectedRing.y))){
					jlblStatus.setText("Can't move a totally Surrounded Ring!");
					return;
			}
			Move m = new Move(new Point(selectedRing.x,selectedRing.y),null,game);
			Point[] moves = m.validMovesNoBlanked(); 
			if(moves.length==0){
				jlblStatus.setText("This Ring has no moves!");
				return;
			}
			
//			for(int i=0;i<moves.length;i++){
//				ringButtons[moves[i].x][moves[i].y].setSelected(true);
//			}
			
			ringButtons[selectedRing.x][selectedRing.y].setSelected(true);
			selectedRingBtn = ringButtons[selectedRing.x][selectedRing.y];
			ringSelected=true;
		}else if(p==Game.DVONN) jlblStatus.setText("You can't move a DVONN ring!");
		else jlblStatus.setText("Pile is controlled by other player!");
	}
	
	public void placeRing(String actionCmd){
		int x ,y;
		if(actionCmd.length()<3){	
			x = Integer.parseInt(actionCmd.charAt(0)+"");
			y = Integer.parseInt(actionCmd.charAt(1)+"");
		}else{
			x = Integer.parseInt(actionCmd.substring(0,2));
			y = Integer.parseInt(actionCmd.charAt(2)+"");
		}
		if(game.board.cells[x][y].valid&&game.board.cells[x][y].cell.size()>0) return;
		
		Ring r;
		if(ringsPlacedNum<3){
			r = new Ring('r',Game.DVONN,"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\red.png","");
			game.board.dvonn[ringsPlacedNum]=r;
			switchPlayerTurn(3);
			if(ringsPlacedNum==2)switchPlayerTurn(1);
		}else if(ringsPlacedNum%2==1){
			r = new Ring('w',Game.PLAYER1,"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\white.png"
					,"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\whiteSelected.png");
			switchPlayerTurn(0);
		}else{
			r = new Ring('b',Game.PLAYER2,"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\black.png",
					"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\blackSelected.png");
			switchPlayerTurn(1);
		}
		game.board.puchRing(r,new Point(x,y));
		paintRings();
		
		ringsPlacedNum++;
		if(ringsPlacedNum==49)game.ringsPlaced=true;
	}
	
	public void paintRings(){
		int countDvonn=0;
		for(int i=0;i<dvonnlbl.length;i++){
			try{
				jplGame.remove(dvonnlbl[i]);
			}catch(Exception ee){}
		}
		for(int i=0; i<11; i++){
			for(int j=0; j<5; j++){
				if(game.board.cells[i][j].valid&&game.board.cells[i][j].cell.size()>0){
					try{
						jplGame.remove(ringButtons[i][j]);
					}catch(Exception e){};
					
					if(!game.board.cells[i][j].blanked){
							ringImg = game.board.cells[i][j].cell.peek().img;
							ringSelImg = game.board.cells[i][j].cell.peek().selectedImg;
						
							if(game.board.cells[i][j].cell.peek().getColor()!='r')
								ringButtons[i][j] = new ringButton(new ImageIcon(ringImg),new ImageIcon(ringSelImg),game.board.cells[i][j].cell.peek().getColor());
							else ringButtons[i][j] = new ringButton(new ImageIcon(ringImg),null,game.board.cells[i][j].cell.peek().getColor());
						
							ringButtons[i][j].setBounds(game.board.cells[i][j].pos.x,game.board.cells[i][j].pos.y, ringImg.getWidth(),ringImg.getHeight());
						
							ringButtons[i][j].addActionListener(this);
							ringButtons[i][j].setActionCommand(i+""+j);
						
							jplGame.add(ringButtons[i][j]);
							jplGame.setComponentZOrder(ringButtons[i][j], 0);
						if(game.board.cells[i][j].cell.peek().getColor()!='r'&&game.board.isDvonn(new Point(i,j))){
							ringImg = Ring.dvonn;
							dvonnlbl[countDvonn]=new JLabel(new ImageIcon(ringImg));
							dvonnlbl[countDvonn].setBounds(game.board.cells[i][j].pos.x+2,game.board.cells[i][j].pos.y+4,ringImg.getWidth(),ringImg.getHeight());
							jplGame.add(dvonnlbl[countDvonn]);
							jplGame.setComponentZOrder(dvonnlbl[countDvonn], 1);
							countDvonn++;
						}
					}
				}
			}
		}
		getContentPane().validate();
		getContentPane().repaint();
	}
	
	public void paintPlayers(){
		jplMain.remove(jplPlayers);
		jplMain.remove(jplStatus);
		
		jplPlayers = new JPanel();
		SpringLayout sLayout = new SpringLayout();
		jplPlayers.setLayout(sLayout);
		jplMain.add(jplPlayers);
		jplMain.add(jplStatus);
		
		jlblPlayers = new JLabel("Players");
		jlblPlayers.setFont(new Font("Times New Roman",Font.BOLD,30));
		jlblPlayers.setForeground(Color.BLUE);
		Font f1 = new Font("Times New Roman",Font.PLAIN,20);
		jlblPl1 = new JLabel("White: "); jlblPl1.setFont(f1);
		jlblPl2 = new JLabel("Black: "); jlblPl2.setFont(f1);	
		jlblN1 = new JLabel(game.p1.getName()); jlblN1.setFont(f1);
		jlblN2 = new JLabel(game.p2.getName()); jlblN2.setFont(f1);
				
		jplPlayers.add(jlblPlayers);
		jplPlayers.add(jlblPl1);
		jplPlayers.add(jlblPl2);
		jplPlayers.add(jlblN1);
		jplPlayers.add(jlblN2);
		
		sLayout.putConstraint(SpringLayout.WEST, jlblPlayers,60,SpringLayout.WEST, jplPlayers);
		sLayout.putConstraint(SpringLayout.NORTH, jlblPlayers,20,SpringLayout.NORTH, jplPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblPl1,50,SpringLayout.WEST, jplPlayers);
		sLayout.putConstraint(SpringLayout.NORTH, jlblPl1,70,SpringLayout.NORTH, jlblPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblPl2,50,SpringLayout.WEST, jplPlayers);
		sLayout.putConstraint(SpringLayout.NORTH, jlblPl2,50,SpringLayout.NORTH, jlblPl1);
		sLayout.putConstraint(SpringLayout.WEST, jlblN1,100,SpringLayout.WEST, jlblPl1);
		sLayout.putConstraint(SpringLayout.NORTH, jlblN1,70,SpringLayout.NORTH, jlblPlayers);
		sLayout.putConstraint(SpringLayout.WEST, jlblN2,100,SpringLayout.WEST, jlblPl2);
		sLayout.putConstraint(SpringLayout.NORTH, jlblN2,50,SpringLayout.NORTH, jlblN1);		
	}
	
	public void clearInvalid(){
		Point[] invalid = game.board.invalidRings();
		for(int i=0; i<invalid.length; i++){
			game.board.cells[invalid[i].x][invalid[i].y].blanked=true;
			ringButtons[invalid[i].x][invalid[i].y].setVisible(false);
			jplGame.remove(ringButtons[invalid[i].x][invalid[i].y]);
		}
	}
	
	public void checkEnd(){
		if(game.board.checkEnd()){
			int winner = game.whoWon();
			switch(winner){
				case 0: jlblStatus.setText("DRAW!!");jlblPlayers.setText("Players: DRAW!!");break;
				
				case 1: jlblStatus.setText(game.p1.getName() + " won!");jlblPlayers.setText("Players: "+game.p1.getName() + " won!");break;
				
				case 2: jlblStatus.setText(game.p2.getName() + " won!");jlblPlayers.setText("Players: "+game.p2.getName() + " won!");break;
				
				default: jlblStatus.setText("ERROR CALCULATING SCORE!");
			}
			switchPlayerTurn(3);
			for(int i=0; i<11; i++){
				for(int j=0; j<5; j++){
					if(game.board.cells[i][j].valid){	
						ringButtons[i][j].removeActionListener(this);
					}
				}
			}
		}
		getContentPane().validate();
		getContentPane().repaint();
	}
	
	public void newGameDialog(){
		jdlgNewGame= new JDialog(this,"New Game");
		jdlgNewGame.setBounds(this.getBounds().x+50,this.getBounds().y+50,500,300);
		jdlgNewGame.setLayout(new SpringLayout());
		jdlgNewGame.setResizable(false);

		jtxtPl1 = new JTextField("Player1");
		jtxtPl2 = new JTextField("Player2");
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
		
		Object[] array = {"Player 1 name:",jtxtPl1, "Player 2 name:", jtxtPl2," ",placeRings,randomGame};
		Object[] options = {jbtnOk,jbtnCancel};
		JOptionPane optionPane = new JOptionPane(array,
                -1,
                JOptionPane.YES_NO_OPTION,
                null,
                options,
                options[0]);

		jdlgNewGame.setContentPane(optionPane);
		jdlgNewGame.setVisible(true);
	}
	
	public void newGame(){
		game.p1.setName(jtxtPl1.getText());
		game.p2.setName(jtxtPl2.getText());
		paintPlayers();
		for(int i=0;i<dvonnlbl.length;i++){
			try{
				jplGame.remove(dvonnlbl[i]);
			}catch(Exception ee){}
		}
		try {
			if(placeRings.isSelected()){
				newNormalGame();
			}
			else if(randomGame.isSelected()){
				newRandGame();
			} 
		}
		catch (IOException e) {
		}
	}
	
	public void newRandGame() throws IOException{
		game.board = new Board(game,true);
		game.ringsPlaced = true;
		switchPlayerTurn(1);
		paintRings();
		getContentPane().validate();
		getContentPane().repaint();
	}
	
	public void newNormalGame() throws IOException{
		game.board = new Board(game,false);
		game.ringsPlaced=false;
		ringsPlacedNum=0;
		switchPlayerTurn(3);
		for(int i=0; i<11; i++){
			for(int j=0; j<5; j++){
				if(game.board.cells[i][j].valid){		
					try{
						jplGame.remove(ringButtons[i][j]);
					}catch(Exception ee){};
					
					ringButtons[i][j] = new ringButton();
					ringButtons[i][j].setBounds(game.board.cells[i][j].pos.x,game.board.cells[i][j].pos.y,Board.width ,Board.height);	
					ringButtons[i][j].addActionListener(this);
					ringButtons[i][j].setActionCommand(i+""+j);
					jplGame.add(ringButtons[i][j]);
					jplGame.setComponentZOrder(ringButtons[i][j], 0);
				}
			}
		}
		
		getContentPane().validate();
		getContentPane().repaint();
	}
	
	public void itemStateChanged(ItemEvent e) {
		
		
	}


	public void actionPerformed(ActionEvent e) {
		String cmd = e.getActionCommand();
		int btnNum=200;
		try{
			btnNum=Integer.parseInt(cmd);
		}
		catch(Exception ee){};
		if("exit".equals(cmd)){
			System.exit(0);
		}else if("newGame".equals(cmd)) {
			newGameDialog();
		}	
		else if("ok".equals(cmd)){
			newGame();
			jdlgNewGame.setVisible(false);
		}
		else if("cancel".equals(cmd)){
			jdlgNewGame.setVisible(false);
		}
		else if(btnNum<105){
			JButton ringBtn = (JButton)(e.getSource());
			if(!game.ringsPlaced){
				placeRing(cmd);
			}else{
				if(!ringSelected) {
					setSelectedRing(cmd);
					selectRing();
				}
				else movePile(cmd,ringBtn);
			}
		}
		getContentPane().validate();
		getContentPane().repaint();	
		
	}
	
	
}

