import java.util.*;
public class Mergesort
{

    void merge(int arr[],int left,int mid,int right)
    {
        int n1=mid-left+1;
        int n2=right-mid;

        int leftarr[]= new int[n1];
        int rightarr[]=new int [n2];

        for(int i=0;i<n1;i++)
            leftarr[i]=arr[left+i];
        for(int j=0;j<n2;j++)
            rightarr[j]=arr[mid+1+j];
        
        int i=0,j=0;
        int k=left;
        while(i<n1 && j<n2)
        {
            if (leftarr[i]<=rightarr[j])
            {
                arr[k]=leftarr[i];
                i++;
            }
            else
            {
                arr[k]=rightarr[j];
                j++;
            }
            k++;
        } 
        while(i<n1)
        {
            arr[k]=leftarr[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            arr[k]=rightarr[j];
            j++;
            k++;
        }



    }
    void mergesort(int arr[],int left,int right)
    {
        if (left<right)
        {
            int mid=(left+right)/2;

            mergesort(arr,left,mid);
            mergesort(arr,mid+1,right);

            merge(arr,left,mid,right);
        }
    } 
    static void printArray(int arr[])
    {
        int n=arr.length;
        for(int i=0;i<n;++i)
        {
            System.out.print(arr[i]+" ");

        }
        System.out.println();

    }
    public static void main(String args[])
    {
        int n;
        Scanner sc= new Scanner(System.in);
        System.out.print("no of ele: ");
        n=sc.nextInt();
        int arr[]=new int [n];
        System.out.println(" enter thr ele: ");
        for(int i=0;i<n;i++)
        {
            
            arr[i] = sc.nextInt();

        }
        System.out.println("original: ");
        printArray(arr);
        
        Mergesort ms= new Mergesort();
        ms.mergesort(arr,0, arr.length-1);
        System.out.println("sort: ");
        printArray(arr);







    }
}