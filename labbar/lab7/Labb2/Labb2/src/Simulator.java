public class Simulator{

    public static void main(String[] args) throws InterruptedException{
        int steps = 10;
        Simulation s = new Simulation(); // TODO: Add parameters!

        for(int i = 0; i < steps; i++){
            System.out.print("\033[2J\033[;H");

            s.step();
            System.out.println(s.intensity);
            Thread.sleep(500);
        }
        System.out.println("");
        System.out.println("Simulation finished!");
    }
}