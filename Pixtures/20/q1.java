class Continent {
    String continentName;

    public Continent(String continentName) {
        this.continentName = continentName;
    }

    public String getContinentName() {
        return continentName;
    }
}

class Country extends Continent {
    String countryName;

    public Country(String continentName, String countryName) {
        super(continentName);
        this.countryName = countryName;
    }

    public String getCountryName() {
        return countryName;
    }
}

class State extends Country {
    String stateName;

    public State(String continentName, String countryName, String stateName) {
        super(continentName, countryName);
        this.stateName = stateName;
    }

    public String getStateName() {
        return stateName;
    }
}

public class q1 {
    public static void main(String[] args) {
        // Create an instance of State
        State myState = new State("North America", "United States", "California");

        // Display information
        System.out.println("Place: " + myState.getStateName());
        System.out.println("State: " + myState.getStateName());
        System.out.println("Country: " + myState.getCountryName());
        System.out.println("Continent: " + myState.getContinentName());
    }
}

