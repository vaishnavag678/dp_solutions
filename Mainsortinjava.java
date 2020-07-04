import java.util.*;
import java.io.*;
import java.lang.*;
//////////////////////////////
class Qsort 
{ 
    int qs;
    Qsort()
    {
        this.qs=0;
    }
    // Nlogn complexity
    public int partition(int arr[], int low, int high) 
    { 
        int pivot = arr[high];   //pivot declared for setup
        int i = (low-1);
        for (int j=low; j<high; j++) 
        { 
            
            if (arr[j] <= pivot) 
            { 
                this.qs++;
                i++; 
                int temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp; 
            } 
        } 
        int temp = arr[i+1]; ///basic swapping 
        arr[i+1] = arr[high]; 
        arr[high] = temp; 
        return i+1; 
    } 
    public void qsort(int arr[], int low, int high) 
    { 
        if (low < high) 
        { 
            this.qs++;
            int pi = partition(arr, low, high);  
            qsort(arr, low, pi-1); 
            qsort(arr, pi+1, high); 
        } 
    }  
} 
class Bsort
{ 
    int bs;
    Bsort()
    {
        this.bs=0;
    }
    public void bsort(int arr[]) 
    { 
        int n = arr.length; 
        /// O(n^2) complexity
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    this.bs++;
                    int temp = arr[j]; 
                    arr[j] = arr[j+1];     //// swapping only simple
                    arr[j+1] = temp; 
                } 
    }  
} 

class Hsort
{ 
    int hs;
    Hsort()
    {
        this.hs=0;
    }

    ///// O(nlogn) complexity in every case where n is size of array
    public void heapify(int arr[], int n, int i) 
    { 
        int largest = i;  
        int l = 2*i + 1;       /// comparing child of i left child
        int r = 2*i + 2;        /// right child of i  
   
        ////basically building min heap for comparison
        if (l < n && arr[l] > arr[largest]){
            this.hs++; 
            largest = l;
        }

        if (r < n && arr[r] > arr[largest]){
            this.hs++; 
            largest = r; 
        }
        if (largest != i) 
        { 
            int swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
            heapify(arr, n, largest); 
        } 
    }

    public void hsort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i); 
        ////sorting the final array in min heap 
        for (int i=n-1; i>0; i--) 
        { 
            int temp = arr[0]; 
            arr[0] = arr[i]; 
            arr[i] = temp; 
            heapify(arr, i, 0); 
        } 
    } 
} 

class Mainsortinjava{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n;
        int i,j,x,y;
        System.out.println("Enter the size of the array");
        n=sc.nextInt();
        int[] a=new int[n+5];
        int[] aa=new int[n+5];
        int[] aaa=new int[n+5];

        for(i=0;i<n;i++)
        {
            x=sc.nextInt();
            a[i]=x;
            aa[i]=x;
            aaa[i]=x;
        } 

        Qsort q=new Qsort();
        Bsort b=new Bsort();
        Hsort h=new Hsort();

        q.qsort(a,0,n-1);
        b.bsort(aa);
        h.hsort(aaa);

        System.out.print("Quick sort requires ");
        System.out.print(q.qs);
        System.out.println(" operations");

        System.out.print("bubble sort requires ");
        System.out.print(b.bs);
        System.out.println(" operations");

        System.out.print("Heap sort requires ");
        System.out.print(h.hs);
        System.out.println(" operations");
    }
}