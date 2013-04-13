package eg.edu.guc.lol.game.champions;

import java.util.HashMap;

public class Skill {
	public static final String[] EFFECTKEYS = {"Heal" , "Stun" , "Silence", "Basic"};
	
	private HashMap<String, Boolean> status;
	private int healthCost;
	private int manaCost;
	private int physicalDamage;
	private int magicalDamage;
	public Skill (int[]costsAndDamage, HashMap<String, Boolean> status){
		healthCost= costsAndDamage[0];
		manaCost= costsAndDamage[1];
		physicalDamage= costsAndDamage[2];
		magicalDamage= costsAndDamage[3];
		this.status = status;
	}
	public boolean isBasic(){
		 return status.get(EFFECTKEYS[3]);
	}
	public boolean isHeal(){
		return status.get(EFFECTKEYS[0]);
	}
	public boolean isStun(){
		return status.get(EFFECTKEYS[1]);
	}
	public int getHealthCost() {
		return healthCost;
	}
	public void setHealthCost(int healthCost) {
		this.healthCost = healthCost;
	}
	public int getManaCost() {
		return manaCost;
	}
	public void setManaCost(int manaCost) {
		this.manaCost = manaCost;
	}
	public int getPhysicalDamage() {
		return physicalDamage;
	}
	public void setPhysicalDamage(int physicalDamage) {
		this.physicalDamage = physicalDamage;
	}
	public int getMagicalDamage() {
		return magicalDamage;
	}
	public void setMagicalDamage(int magicalDamage) {
		this.magicalDamage = magicalDamage;
	}
	public boolean isSilence(){
		return status.get(EFFECTKEYS[2]);
	}
	public void setHeal(boolean heal){
		status.put(EFFECTKEYS[0], heal);
	}
	public void setStun(boolean stun){
		status.put(EFFECTKEYS[1], stun);
	}
	public void setSilence(boolean silence){
		status.put(EFFECTKEYS[0], silence);
	}
	public String toString() {
		return "This skill has " + (isHeal()?"":"no ") + " Heal Ability.\n" +
				"This skill has " + (isStun()?"":"no ") + " Stun Ability.\n" +
				"This skill has " + (isSilence()?"":"no ") + " Silence Ability.\n" +
				"This skill has " + (isBasic()?"":"no ") + " Basic Ability.\n" +
				"This skill has " + getHealthCost() +  " Health Cost.\n" +
				"This skill has " + getManaCost() +  " Mana Cost.\n" +
				"This skill has " + getPhysicalDamage() +  " Physical Damage.\n" +
				"This skill has " + getPhysicalDamage() +  " Magical Damage.\n";			
	}	
}
