import java.util.Scanner;

public class Main{
    public static void main(String[ ] args){
        Scanner input = new Scanner(System.in);
        int in = input.nextInt();
        for(int i=1;i<=in;i++){
            int first_start = in+1-i;
            for(int j=1;j<=in;j++){
                if(j>=first_start){
                    System.out.print('*');
                }
                else{
                    System.out.print(' ');
                }
            }
            System.out.println();
        }
    }
}
