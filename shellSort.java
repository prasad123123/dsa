import java.util.*;
public class shellSort
{
    static void printArray(int arr [])
    {
        int n=arr.length;
        for(int  i=0;i<n;i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    int sort(int arr[])
    {
        int n=arr.length;
        for(int gap=n/2;gap>0;gap/=2)
        {
            for(int i=gap;i<n;i+=1)
            {
                int temp=arr[i];
                int j;
                for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                {
                    arr[j]=arr[j-gap];
                }
                arr[j]=temp;
            }
        }
        return 0;
    }
    public static void main(String args[])
    {
        int n;
        Scanner sc= new Scanner(System.in);
        System.out.print("enter no. of element : ");
        n= sc.nextInt();
        int arr[] = new int[n];
        System.out.print("Enter ele of arr : ");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        System.out.println("main array: ");
        printArray(arr);
        System.out.println("sort : ");
        shellSort ob=new shellSort();
        ob.sort(arr);
        printArray(arr);
    }
}