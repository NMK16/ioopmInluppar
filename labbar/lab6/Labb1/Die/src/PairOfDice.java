public class PairOfDice {
    public static void main(String[] args) {
        int numberOfSides = 10;
        Die die = new Die(numberOfSides);
        Die die2 = new Die(numberOfSides);
        die.roll();
        die2.roll();
        System.out.println(die.toString());
        System.out.println(die2.toString());
    }
}
