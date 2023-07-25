class Box{
    double width, height, depth;
    public void calc_vol(){
        System.out.println("Volume of the box is: ");
        System.out.println(width * height * depth);
    }
}

class BoxDemo1 {
    public static void main(String args[]){
        Box mybox = new Box();
        mybox.width = 10;
        mybox.height = 15;
        mybox.depth = 20;
        mybox.calc_vol();
    }    
}
