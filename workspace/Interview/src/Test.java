import static org.junit.Assert.*;

public class Test {
	@org.junit.Test
	public void testMethod() {
		assertEquals(
				Main.change("This 44 a long string that should be changed"),
				"This Fizz Buzz Fizz string FizzBuzz should Fizz Buzz");
		assertEquals(Main.change(""),"");
		assertEquals(Main.change(null),"");
	}
}
