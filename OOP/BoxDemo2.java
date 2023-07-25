import java.util.*;
class Box{
    double width, height, depth, vol = 0;
    public void setData(){
	Scanner sc = new Scanner(System.in); 
        //double width, height, depth, vol = 0;
	    System.out.println("Enter the side of a box: ");
	    width = sc.nextDouble();
        height = sc.nextDouble();
	    depth = sc.nextDouble();
    
    }
    
    void calc_vol(double width, double height, double depth, double vol){
        vol = width * height * depth;
        System.out.println("Volume of the Box is: " + vol);
    }
}

public class BoxDemo2 extends Box{
    public static void main(String[] args) {
        Box sq = new Box();
        Box rect = new Box();
        
	    sq.setData();
        sq.calc_vol(sq.width, sq.height, sq.depth, sq.vol);
        
        rect.setData();
        rect.calc_vol(rect.width, rect.height, rect.depth, rect.vol);

        if(sq.vol > rect.vol) System.out.println("The volume of cube is greater.");
        else { System.out.println("The volume of cuboid is greater."); }
    }
}
