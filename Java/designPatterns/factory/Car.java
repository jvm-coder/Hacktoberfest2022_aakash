/**
 * represents a generic car
 */
public abstract class Car {

    public abstract String getDescription();

    public abstract int getSeats();

    @Override
    public String toString(){
        return "description: " + this.getDescription() + " seats: " + this.getSeats();
    }
}
