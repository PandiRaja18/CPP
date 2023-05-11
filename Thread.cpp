#include<iostream>
using namespace std;
class book {
	// tickets is static so all book objects have the same ticket count
	static int tickets = 1;
	// synchronized method to book movie ticket
	synchronized void book(int request, String name)
	{
		// logic to book ticket
		if (tickets >= request) {
			System.out.println(name + " booked " + request
							+ " ticket.");
			tickets = tickets - 1;
			System.out.println("Tickets left: " + tickets);
		}
		else {
			System.out.println("No tickets are available.");
		}
	}
}
// Helper class 2, extending Thread class.
// book method is called from this class using the object
// passed from main class.
class myThread extends Thread {
	book obj;
	int n;
	String name;
	myThread(book obj, String name, int n)
	{
		this.obj = obj;
		this.n = n;
		this.name = name;
	}
	// runs threads
	public void run() { obj.book(n, name); }
}
// Driver class
public class GFG {
	// Driver method
	public static void main(String[] args)
	{
		// Creating multiple objects "obj" and "obj2" of
		// book class and passing it to myThread class.
		book obj = new book();
		book obj2 = new book();
		myThread t1 = new myThread(obj, "Shubham", 1);
		myThread t2 = new myThread(obj2, "Sharmistha", 1);
		// When a program calls the start() method, a new
		// thread is created and then the run() method is
		// executed.

		// Starting threads created above
		t1.start();
		t2.start();
	}
}
