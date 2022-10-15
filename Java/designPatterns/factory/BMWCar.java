/**
 * represents a specific car
 */
public class BMWCar extends Car{

    private String description;
    private int seats;

    public BMWCar(String description, int seats){
        this.description = description;
        this.seats = seats;
    }
    @Override
    public String getDescription() {
        return this.description;
    }

    @Override
    public int getSeats() {
        return this.seats;
    }
}
