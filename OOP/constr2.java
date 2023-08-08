/**
 * Create a class having a copy constructor. Add a method to check and 
 * return whether two objects of the class are equal or not. 
 */

class Box{
    int length;
    int width;
    int height;

    public Box(int length, int width, int height){
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public Box(Box ob){
        this.length = ob.length;
        this.width = ob.width;
        this.height = ob.height;
    }
}

class constr2{
    public static void main(String []args) {
        Box mybox = new Box(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2]));
        Box clone = new Box(mybox);

        if((mybox.length == clone.length) && (mybox.width == clone.width) 
            && (mybox.height == clone.height))
            System.out.println("The two objects of the class are equal.");
        else System.out.println("The two objects of the class are not equal.");
    }
}
 