import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Calendar;

import org.junit.Before;
import org.junit.Test;

import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Farmer;
import eg.edu.guc.voting.participants.Independent;
import eg.edu.guc.voting.participants.Worker;


public class CandidateTest {
	private Calendar birthDate1, birthDate2;
	
	@Before
	public void setup() {
		birthDate1 = Calendar.getInstance();
		birthDate1.add(Calendar.YEAR, -23);
		
		birthDate2 = Calendar.getInstance();
		birthDate2.add(Calendar.YEAR, -18);
	}
	
	@Test(timeout = 1000)
	public void hasIndependentConstructor() {
		new Independent("123456789", "name", birthDate1, "Mr.");
	}
	
	@Test(timeout = 1000)
	public void hasFarmerConstructor() {
		new Farmer("123456789", "name", birthDate1, "Mr.");
	}
	
	@Test(timeout = 1000)
	public void hasWorkerConstructor() {
		new Worker("123456789", "name", birthDate1, "Mr.");
	}
	
	@Test(timeout = 1000)
    public void testHierarchy() {
		Independent independent = new Independent("123456789", "name", birthDate1, "Mr.");
        assertTrue("Independent must be a subclass of Civilian",
        		independent instanceof Civilian);
        Farmer farmer = new Farmer("123456789", "name", birthDate1, "Mr.");
        assertTrue("Farmer must be a subclass of Civilian",
        		farmer instanceof Civilian);
        Worker worker = new Worker("123456789", "name", birthDate1, "Mr.");
        assertTrue("Worker must be a subclass of Civilian",
        		worker instanceof Civilian);
    }
	
	@Test(timeout = 1000)
    public void testIndependentToString() {
		Independent independent = new Independent("123456789", "name", birthDate1, "Mr.");
		String s  =  independent.toString().toLowerCase();
		assertTrue(s.startsWith("candidate"));
		assertTrue(s.contains("mr."));
		assertTrue(s.contains("name"));
		assertTrue("String representation of civilian should contain the age",
				s.contains("23"));
    }
	
	@Test(timeout = 1000)
    public void testFarmerToString() {
		Farmer farmer = new Farmer("123456789", "name", birthDate1, "Mr.");
		String s  =  farmer.toString().toLowerCase();
		assertTrue(s.startsWith("candidate"));
		assertTrue(s.contains("mr."));
		assertTrue(s.contains("name"));
		assertTrue("String representation of civilian should contain the age",
				s.contains("23"));
    }
	
	@Test(timeout = 1000)
    public void testWorkerToString() {
		Worker worker = new Worker("123456789", "name", birthDate1, "Mr.");
		String s  =  worker.toString().toLowerCase();
		assertTrue(s.startsWith("candidate"));
		assertTrue(s.contains("mr."));
		assertTrue(s.contains("name"));
		assertTrue("String representation of civilian should contain the age",
				s.contains("23"));
    }
	
	@Test(timeout = 1000)
    public void testIndependentEquality() {
		Independent independent = new Independent("123456789", "name", birthDate1, "Mr.");
		Independent independent2 = new Independent("123456789", "name", birthDate2, "Mr.");
		Independent independent3 = new Independent("123456789", "name", birthDate1, "Mr.");
		assertTrue(independent.equals(independent));
		assertFalse(independent.equals(independent2));
		assertTrue(independent.equals(independent3));
    }
	
	@Test(timeout = 1000)
    public void testFarmerEquality() {
		Farmer farmer = new Farmer("123456789", "name", birthDate1, "Mr.");
		Farmer farmer2 = new Farmer("a diffferent id", "name", birthDate1, "Mr.");
		Farmer farmer3 = new Farmer("123456789", "name", birthDate1, "Mr.");
		assertTrue(farmer.equals(farmer));
		assertFalse(farmer.equals(farmer2));
		assertTrue(farmer.equals(farmer3));
    }
	
	@Test(timeout = 1000)
    public void testWorkerEquality() {
		Worker worker = new Worker("123456789", "name", birthDate1, "Mr.");
		Worker worker2 = new Worker("123456789", "name", birthDate2, "Mrs.");
		Worker worker3 = new Worker("123456789", "name", birthDate1, "Mr.");
		assertTrue(worker.equals(worker));
		assertFalse(worker.equals(worker2));
		assertTrue(worker.equals(worker3));
    }
	
	@Test(timeout = 1000)
    public void testDifferentTypesEquality() {
		Independent independent = new Independent("123456789", "name", birthDate1, "Mr.");
        Farmer farmer = new Farmer("123456789", "name", birthDate1, "Mr.");
        Worker worker = new Worker("123456789", "name", birthDate1, "Mr.");
        assertFalse(independent.equals(farmer));
        assertFalse(farmer.equals(independent));
        assertFalse(independent.equals(worker));
        assertFalse(worker.equals(independent));
        assertFalse(farmer.equals(worker));
        assertFalse(worker.equals(farmer));
    }
}
