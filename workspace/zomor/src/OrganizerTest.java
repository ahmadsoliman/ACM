import static org.junit.Assert.assertTrue;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.junit.Before;
import org.junit.Test;

import eg.edu.guc.voting.Organizer;

public class OrganizerTest {

	private String text;

	@Before
	public void setUp() throws Exception {
		text = "1\n"
				+ "Civilian,14879199747,Linwood Nikolaus IV,06/04/1989,Ms\n"
				+ "Civilian,1430794265912889,Miss Marley Jewess,10/06/2001,Mrs\n"
				+ "Civilian,19789989883057,Dr. Osborne Sauer,12/21/1971,Mr\n"
				+ "Civilian,60443841772989,Ms. Justice Wisoky,09/04/1986,Mr\n"
				+ "Civilian,18932617756,Franz Abshire,12/01/1988,Ms\n"
				+ "Civilian,16989799697,Cleta Greenholt,08/12/2007,Ms\n"
				+ "\n"
				+ "Worker,2038563097,Elna Treutel,08/20/1973,Ms\n"
				+ "Independent,178925212507641,Rose Dickens,11/02/1969,Mrs\n"
				+ "Independent,18345035310,Rodolfo Dietrich DDS,07/21/2001,Mrs\n"
				+ "\n" + "1\n" + "Sauer  Will and Gerhold\n" + "2\n"
				+ "8938168166,Miss Saul Blick,11/01/2002,Ms\n"
				+ "228353419865267,Zena Nader,06/25/1989,Mrs\n" + "\n"
				+ "18932617756,Sauer  Will and Gerhold,178925212507641\n"
				+ "14879199747,Sauer  Will and Gerhold,18345035310\n"
				+ "19789989883057,Sauer  Will and Gerhold,178925212507641\n"
				+ "14879199747,Sauer  Will and Gerhold,178925212507641\n"
				+ "#######################################################";
	}

	@Test(timeout = 1000)
	public void hasOrganizerConstuctor() throws Exception {
		InputStream is = new ByteArrayInputStream(text.getBytes("UTF-8"));
		new Organizer(new InputStreamReader(is));
	}

	@Test(timeout = 1000)
	public void testToString() throws Exception {
		InputStream is = new ByteArrayInputStream(text.getBytes("UTF-8"));
		Organizer o = new Organizer(new InputStreamReader(is));
		String s = o.toString();
		assertTrue(
				"Organizer's string representation should contain the number of elligible voters",
				s.contains("4"));
		assertTrue(
				"Organizer's string representation should contain the number of candidates",
				s.contains("3"));
		assertTrue(
				"Organizer's string representation should contain the number of parties",
				s.contains("1"));
	}
}
