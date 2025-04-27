import java.util.Scanner;

public class Main {
    public static void main(String[ ] args){
        Scanner input = new Scanner(System.in);
        int in = input.nextInt();
        input.nextLine();
        int score;
        int succes;
        for(int i=0;i<in;i++)
        {
            String haha = input.nextLine();
            score = 0;
            succes = 0;
            for(int j=0;j<haha.length();j++){
                if(haha.charAt(j)=='O'){
                    succes++;
                    score+=succes;
                }else if(haha.charAt(j)=='X'){
                    succes=0;
                }
            }
            System.out.println(score);
        }
    }
}
