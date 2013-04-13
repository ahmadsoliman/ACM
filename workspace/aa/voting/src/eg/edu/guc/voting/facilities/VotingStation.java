package eg.edu.guc.voting.facilities;

public abstract class VotingStation {
	protected String location;
	protected int capacity;
	
		public VotingStation()
		{
			location = "";
			capacity = 0;
			
		}
		public VotingStation(int capacity)
		{
			this.location = "";
			this.capacity = capacity;
		}
		public abstract int getCapacity();
		
		public String toString()
		{
			return "capacity =" + capacity + "location =" + location;
			
		}
		public String getLocation() {
			return location;
		}
		public void setLocation(String location) {
			this.location = location;
		}
	}


