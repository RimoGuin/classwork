/*Create a class called Room with data members length, breadth and height
 and method calc_area to calculate the area of the room and display it. Derive
 2 subclasses from this class having the names bedroom and drawing room where 
 bedroom will have attached bathroom, study table and night lamp and a display method
 to display all those features. Drawing room will have sofa and wall cabinet and 
 a display method to do the same. Also display the areas of both bedroom and drawing room. 
 */

 class Room{
    private int length;
    private int breadth;
    private int height;

    public Room(int length, int breadth, int height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    public int getArea() {
        return this.length * this.breadth;
    }

    public void display() {
        System.out.println("Length: " + this.length);
        System.out.println("Breadth: " + this.breadth);
        System.out.println("Height: " + this.height);
        System.out.println("Area: " + this.getArea());
    }
 }

 class Bedroom extends Room {
    private boolean attachedBathroom;
    private boolean studyTable;
    private boolean nightLamp;

    public Bedroom(int length, int breadth, int height, boolean attachedBathroom, boolean studyTable, boolean nightLamp) {
        super(length, breadth, height);
        this.attachedBathroom = attachedBathroom;
        this.studyTable = studyTable;
        this.nightLamp = nightLamp;
    }

    public void display() {
        super.display();
        System.out.println("Attached Bathroom: " + this.attachedBathroom);
        System.out.println("Study table: " + this.studyTable);
        System.out.println("Night lamp: " + this.nightLamp);
    }
 }

  class DrawingRoom extends Room {
    private boolean sofa;
    private boolean wallCabinet;

    public DrawingRoom(int length, int breadth, int height, boolean sofa, boolean wallCabinet) {
        super(length, breadth, height);
        this.sofa = sofa;
        this.wallCabinet = wallCabinet;
    }

    public void display() {
        super.display();
        System.out.println("Sofa: " + this.sofa);
        System.out.println("Wall cabinet: " + this.wallCabinet);
    }
 }

 public class RoomMain {
    public static void main(String[] args) {
        Bedroom bedroom = new Bedroom(10, 5, 3, true, true, true);
        bedroom.display();
        System.out.println();
        DrawingRoom drawingRoom = new DrawingRoom(12, 6, 4, true, true);
        drawingRoom.display();
    }
}