class Box{
	double width;
	double height;
	double depth;
}

class BoxDemo{
	public static void main(String args[]){
		double volume;
		Box mybox = new Box();
		mybox.width = 10;
		mybox.height = 15;
		mybox.depth = 20;
		volume = mybox.width * mybox.height * mybox.depth;
		System.out.println("Volume of the box is:" + volume);
	}
}