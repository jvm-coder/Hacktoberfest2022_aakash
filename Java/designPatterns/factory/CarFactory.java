/**
 * just a car factory
 */
public class CarFactory {

    public static Car getCar(String type, String description, int seats){
        if(type.equals("bmw"))
            return new BMWCar(description, seats);

        return null;
    }
}
