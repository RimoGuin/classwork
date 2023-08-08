/*
Create a class with data members and all possible types of construcors 
so as to implement constructor overloading. User display method to 
demonstrate the calling of each type of constructor. 
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

    public Box(){
        length = -1;
        width = -1;
        height = -1;
    }

    public Box(Box ob){
        length = ob.length;
        width = ob.width;
        height = ob.height;
    }

    double volume(){
        return (length * width * height);
    }
}

class constr1{
    public static void main(String []args){
        Box mybox1 = new Box(10, 15, 20);
        Box mybox2 = new Box(); 

        Box myclone = new Box(mybox1); // Copy constructor

        double vol;
        vol = mybox1.volume();
        System.out.println("Volume of mybox1 is " + vol);

        vol = mybox2.volume();
        System.out.println("Volume of mybox2 is " + vol);

        vol = myclone.volume();
        System.out.println("Volume of clone is " + vol);
    }
}