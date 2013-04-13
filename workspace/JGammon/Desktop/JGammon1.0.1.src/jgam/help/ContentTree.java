/*
 JGammon: A Backgammon client with nice graphics written in Java
 Copyright (C) 2005 Mattias Ulbrich

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
package jgam.help;

import javax.swing.JEditorPane;
import javax.swing.JTree;
import java.io.*;
import javax.swing.tree.*;
import java.util.ResourceBundle;
import javax.swing.event.*;

/**
 * A JTree that is used in a HelpFrame-Context.
 *
 * A hierachy of help topics is loaded in a treefrom and each node can be
 * selected and is subsequently loaded into the HelpFrame-Content-Area.
 *
 * The tree-structure is read from a file.
 * This is locale-dependent. The filename is stored in the resource "jgam.msg.Help->tocFile"
 *
 * The tree structure is represented by leading spaces. For instance:
 *
 * A.html textA
 *  B.html#topic1 textB
 *   C.html textC contains spaces which is ok
 *  D.htm textD
 *   E.html textE
 *   F.txt textF
 *
 * First token is the resource to be loaded, second and following are the
 * description.
 *
 * @author Mattias Ulbrich
 */
public class ContentTree extends JTree implements TreeSelectionListener {

    private ResourceBundle msg = ResourceBundle.getBundle("jgam.msg.Help");
    private HelpFrame helpFrame;
    private static final int MAXLEVEL = 4;

    public ContentTree(HelpFrame helpFrame) throws IOException {
        super();
        this.helpFrame = helpFrame;
        setModel(new DefaultTreeModel(readin()));
        addTreeSelectionListener(this);
    }

    private DefaultMutableTreeNode readin() throws IOException {
        DefaultMutableTreeNode levels[] = new DefaultMutableTreeNode[MAXLEVEL];
        BufferedReader br = new BufferedReader(new InputStreamReader(getClass().
                getResourceAsStream(msg.getString("tocFile"))));

        while (br.ready()) {
            String line = br.readLine();
            int level = countInitialSpaces(line);
            DefaultMutableTreeNode tn = new DefaultMutableTreeNode(new Item(
                    line.trim()));
            if (level != 0) {
                levels[level - 1].add(tn);
            }
            levels[level] = tn;
        }

        return levels[0];
    }

    private int countInitialSpaces(String string) {
        for (int i = 0; i < string.length(); i++) {
            if (string.charAt(i) != ' ') {
                return i;
            }
        }
        return string.length();
    }

    /**
     * TreeSelectionListener must implement this.
     * Show the selected page.
     *
     * @param e TreeSelectionEvent
     */
    public void valueChanged(TreeSelectionEvent e) {
        DefaultMutableTreeNode node = (DefaultMutableTreeNode)
                                      getLastSelectedPathComponent();
        Item item = (Item) node.getUserObject();
        try {
            helpFrame.showPage(item.page);
        } catch (IOException ex) {
            System.err.println("Could not load page: " + item.page);
            ex.printStackTrace();
        }
    }

    /**
     * An item in the tree.
     * Read from a text file line
     * <page> <space> <Description>
     */
    class Item {
        String desc;
        String page;
        Item(String line) {
            int firstspace = line.indexOf(' ');
            page = line.substring(0, firstspace);
            desc = line.substring(firstspace + 1);
        }

        public String toString() {
            return desc;
        }
    }
}
