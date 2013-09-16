package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

interface DirContent{
	public String getName();
}
class File implements DirContent{
	String name;
	int size;
	public File(String name, int size) {
		this.name = name;
		this.size = size;
	}
	public String getName() {
		return this.name;
	}
}
class Directory implements DirContent{
	String name;
	Directory parent;
	Vector<DirContent> list;
	public Directory(String name, Directory parent ,Vector<DirContent> list) {
		this.name = name;
		this.parent = parent;
		this.list = list;
	}
	public String getName() {
		return this.name;
	}
}

public class Deltree {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer res = new StringBuffer();
		while(true){
			Directory root = new Directory("root", null, new Vector<DirContent>());
			Directory currentDir = root;
			String input = br.readLine();
			while(!input.equals("")){
				if(input.equals(">exit")){
					res.deleteCharAt(res.lastIndexOf("\n"));
					System.out.println(res.toString());
					return;
				}else if(input.contains("cd")){
					String[] cdClause = input.split(" ");
					if(cdClause[1].equals("\\")){
						currentDir = root;
					}else if(cdClause[1].equals("..")){
						currentDir = currentDir.parent;
					}else if(cdClause[1].startsWith("\\")){
						currentDir = root;
						currentDir = moveDir(currentDir, cdClause[1].substring(1));
					}else{
						//normal dir
						currentDir = moveDir(currentDir, cdClause[1]);
					}
				}else if(input.contains("dir")){
					String dirElem = br.readLine();
					while(!dirElem.startsWith(">")){
						String[] elems = dirElem.split(" ");
						if(elems.length==1){
							insertDir(currentDir, dirElem);
						}else{
							insertFile(currentDir, elems[0], Integer.parseInt(elems[1]));
						}
						dirElem = br.readLine();
					}
					input = dirElem;
					continue;
				}else if(input.contains("deltree")){
					//process
					String[] elems = input.split(" ");
					if(elems[1].contains("\\")){
						currentDir = root;
						currentDir = moveDir(currentDir, elems[1].substring(1));
						currentDir = currentDir.parent;
						String[] elem2 = elems[1].substring(1).split("\\\\");
						elems[1] = elem2[elem2.length-1];
					}
					res.append(calcDeletion(currentDir,elems[1]));
					res.append("\n");
				}
				input = br.readLine();
			}
		}
	}
	
	private static int calcDeletion(Directory startDir, String dirName) {
		int foundI = -1;
		if(startDir == null || startDir.list==null)return 0;
		for (int j = 0; j < startDir.list.size(); j++) {
			if(startDir.list.get(j).getName().equals(dirName))
				foundI = j;
		}
		if(foundI==-1) return 0;
		Directory currentDir = (Directory)startDir.list.get(foundI);
		int size = 0;
		for (int i = 0; i < currentDir.list.size(); i++) {
			DirContent elem = currentDir.list.get(i);
			if(elem instanceof Directory){
				size += calcDeletion(currentDir, currentDir.list.get(i).getName());
			}else{
				size += ((File)currentDir.list.get(i)).size;
			}
		}
		return size;
	}


	public static void insertFile(Directory currentDir, String fileName, int size){
		int foundI = -1;
		for (int j = 0; j < currentDir.list.size(); j++) {
			if(currentDir.list.get(j).getName().equals(fileName))
				foundI = j;
		}
		if(foundI==-1){
			File file = new File(fileName, size);
			currentDir.list.add(file);
		}
	}
	public static void insertDir(Directory currentDir, String destName){
		int foundI = -1;
		for (int j = 0; j < currentDir.list.size(); j++) {
			if(currentDir.list.get(j).getName().equals(destName))
				foundI = j;
		}
		if(foundI==-1){
			Directory dest = new Directory(destName, currentDir, new Vector<DirContent>());
			currentDir.list.add(dest);
		}
	}
	public static Directory moveDir(Directory currentDir, String destName){
		String[] subDirs;
		if(destName.contains("\\")){
			subDirs = destName.split("\\\\");
		}else{
			subDirs = new String[]{destName};
		}
		for (int i = 0; i < subDirs.length; i++) {
			int foundI = -1;
			for (int j = 0; j < currentDir.list.size(); j++) {
				if(currentDir.list.get(j).getName().equals(subDirs[i]))
					foundI = j;
			}
			if(foundI==-1){
				currentDir.list.add(new Directory(subDirs[i], currentDir, new Vector<DirContent>()));
				currentDir = (Directory)currentDir.list.get(currentDir.list.size()-1);
			}else{
				currentDir = (Directory)currentDir.list.get(foundI);
			}
		}
		return currentDir;
	}
}
