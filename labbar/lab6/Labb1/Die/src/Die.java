
public class Die {
  private int numberOfSides;
  private int value;

  public Die() {
    this.numberOfSides = 6;
  }
  public Die(int numberOfSides) {
    this.numberOfSides = Math.abs(numberOfSides);
  }
  public int roll() {
    this.value = (int) (Math.random() * numberOfSides) + 1;
    return this.get();
  }
  public String toString() {
    return "Die(" + value + ")";
  }
  public int get() {
    return value;
  }
  public boolean equals(Die otherDie){
    return (otherDie.numberOfSides == numberOfSides) && (otherDie.value == value);
  }

}