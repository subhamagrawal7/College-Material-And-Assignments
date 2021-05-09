import java.io.*;
import java.util.*;
import java.lang.*;


class A{
    
    public static void main(String Args[]) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("How many ques u want to have: ");
        int n=Integer.parseInt(br.readLine());
        // ArrayList <Abc> ar=new ArrayList <Abc>();
        
        int i,j,k;
        String s;
        int w[]=new int[n];
        int length[]=new int[n];

        for(i=0;i<n;i++){
            System.out.println("How much weights u want to have of the Queues : "+(i+1));
            w[i]=Integer.parseInt(br.readLine());
        }

        String data[]=new String [n];
        int len=0;
        int max=0;

        for(i=0;i<n;i++){
            System.out.println("How data of the Queues : "+(i+1));
            data[i]=br.readLine();
            length[i]=(int)Math.ceil(data[i].length()/(8*w[i]));
            max=Math.max(length[i],max);
        }

        int size=8;
        
        int time=0;

        String output="";
        while(max-- >0){
            for(i=0;i<n;i++){
                System.out.print("Current output for Queue "+(i+1)+" is : ");
                output="";
                int p=time*8;
                if(p < data[i].length()){
                    for(j=0;j<w[i]*8;j++){
                        if(j%8==0){
                            output+=" ";
                        }

                        if( (p+j) < data[i].length()){
                            output+=data[i].charAt(p+j);
                        }
                    }
                    System.out.println(output);
                }
                else{
                    System.out.println("No data left");
                }
            }
            time++;
        }
    }
}