class B extends A {
	int x, z;

	B() {
		super(1);
		System.out.println("b");
		x = 3;
		y = 4;
		z = 5;
	}

	int getx() {
		return 15;
	}

	int getz() {
		return z;
	}
}