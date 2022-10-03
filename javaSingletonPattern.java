import java.io.*;
 
// Class 1
// Helper class
class SingletonEagar {
 
    // Declaration and definition of variable occur
    // simultaneously
    //  Eager initialisation
    private static SingletonEagar instance
        = new SingletonEagar();
 
    // Private constructor of class 1
    private SingletonEagar() {}
 
    public static SingletonEagar getInstance()
    {
        return instance;
    }
}
 
// Class 2
// Helper Class
class Singleton {
 
    // Lazy  declaration and initialisation
    private static Singleton instance;
 
    // Private constructor of Class 2
    private Singleton() {}
 
    public static Singleton getInstance()
    {
 
        // Condition check
        // When instance is null
        // a new object of Singleton class is created
        if (instance == null) {
            instance = new Singleton();
        }
 
        return instance;
    }
}
 
// Class 3
// Helper class
class SingletonSynchronizedMethod {
 
    private static SingletonSynchronizedMethod instance;
 
    // Private constructor of Class 3
    private SingletonSynchronizedMethod() {}
 
    public static synchronized SingletonSynchronizedMethod
    getInstance()
    {
 
        // Condition check
        // When instance is null
        // a new object of Singleton class is created
        if (instance == null) {
            instance = new SingletonSynchronizedMethod();
        }
 
        return instance;
    }
}
 
// Class 4
// Helper class
class SingletonSynchronized {
 
    private static SingletonSynchronized instance;
 
    // Private constructor of Class 4
    private SingletonSynchronized() {}
 
    public static SingletonSynchronized getInstance()
    {
 
        // Again, condition check
        if (instance == null) {
 
            // synchronized block
            synchronized (SingletonSynchronized.class)
            {
 
                if (instance == null) {
                    instance = new SingletonSynchronized();
                }
            }
        }
        return instance;
    }
}
 
// Class 5
// Main class (SingletonExample)
public class GFG {
 
    // Main driver method
    public static void main(String[] args)
    {
 
        // Creating instance in main() method of class 1
        SingletonEagar instance1
            = SingletonEagar.getInstance();
 
        // Display message only
        System.out.println(
            instance1
            + " : Singleton Eager initialisation ");
 
        // Creating instance in main() method of class 2
        Singleton instance2 = Singleton.getInstance();
 
        // Display message only
        System.out.println(
            instance2
            + " : Singleton Lazy initialisation ");
 
        // Creating instance in main() method of class 4
        SingletonSynchronized instance3
            = SingletonSynchronized.getInstance();
 
        // Display message only
        System.out.println(instance3
                           + " : Synchronized Singleton");
    }
}
