class Box {
    double width, height, depth, side, vol = 0;

    // Constructor with parameters
    
    public Box(double width, double height, double depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    // Method to calculate the volume of the box
    public void calc_vol() {
        vol = width * height * depth;
        System.out.println("Volume of the Box is: " + vol);
    }
}

public class BoxConst2 {
    public static void main(String[] args) {
        // Create two boxes with different dimensions
        Box sq = new Box(20, 20, 20);
        Box rect = new Box(20, 30, 40);

        // Calculate the volume of the boxes
        sq.calc_vol();
        rect.calc_vol();

        // Check which box has the greater volume
        if (sq.vol > rect.vol) {
            System.out.println("The volume of cube is greater.");
        } else {
            System.out.println("The volume of cuboid is greater.");
        }
    }
}
