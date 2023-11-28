// Base class - Continent
class Continent {
    String continentName;

    public Continent(String continentName) {
        this.continentName = continentName;
    }

    public String getContinentName() {
        return continentName;
    }
}

// Derived class - Country (inherits from Continent)
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

// Derived class - State (inherits from Country)
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

public class q1{
    public static void main(String[] args) {
        // Create an object of State
        State myState = new State("Asia", "India", "Karnataka");

        // Display place, state, country, and continent
        System.out.println("Place: " + myState.getStateName());
        System.out.println("State: " + myState.getStateName());
        System.out.println("Country: " + myState.getCountryName());
        System.out.println("Continent: " + myState.getContinentName());
    }
}

