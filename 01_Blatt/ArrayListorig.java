public class ArrayListorig {

    private static final int BASE_SIZE = 32;

    private int[] array;
    private int size;
    private int capacity;

    // Return the current number of elements.
    public int size()
    {
        return this.size;
    }
    // Return the currently available size.
    public int capacity()
    {
        return this.capacity;
    }
    // Construct a new ArrayList with some space.
    public ArrayListorig()
    {
        this.capacity = BASE_SIZE;
        this.size = 0;
        this.array = new int[this.capacity];
    }

    private void increaseCapacity () {
        this.capacity = (this.capacity * 3) / 2 + 1;
        this.resizeArray();
    }

    private void resizeArray() {
        if (this.array.length < this.capacity) {
            int[] newArray = new int[this.capacity];
            for (int index = 0; index < this.array.length; index++) {
                newArray[index] = this.array[index];
            }
            this.array = newArray;
        }
    }
    // Increase the capacity to hold at least newSize elements.
    // This method never decreases the size of the ArrayList!
    public void reserve(int newSize)
    {
        if (newSize > this.capacity) {
            this.capacity = newSize;
            this.resizeArray();
        }
    }
    // Add an element to the back of the ArrayList.
    public void push_back(int element)
    {
        this.size++;
        if (this.size >= this.capacity) {
            this.increaseCapacity();
        }
        this.array[size-1] = element;
    }
    // Remove the last element from the ArrayList.
    public void pop_back()
    {
        this.array[this.size-1] = 0;
        this.size--;
    }
    // Return the value at the given position.
    public int get_at(int index)
    {
        if (0 <= index && index < size) {
            return this.array[index];
        } 
        return -1; // i'd rather throw an exception
    }
    // Set the value at the given position.
    public void set_at(int index, int element)
    {
        if (0 <= index && index < size) {
            this.array[index] = element;
        } 
        // probably should throw an exception
    }
    // Insert the element at the given index. 
    // The elements after that position are shifted towards the back.
    public void insert(int index, int element)
    {
        if (this.size + 1 >= this.capacity) {
            this.increaseCapacity();
        }
        if (index >= this.capacity) {
            this.reserve(index+1);
        }
        this.size++;
        if (0 <= index) {
            int newValue = element;
            int temp;
            for (int i = index; i < this.size; i++) {
                temp = this.array[i];
                this.array[i] = newValue;
                newValue = temp;
            }
        } 
        // probably should throw an exception
    }
    // Erase a block of elements of size length, starting at index.
    // The elements following this block are shifted towards the front.
    public void erase(int index, int length)
    {
        if (length < 0) {
            return; // rather throw something
        }
        if (0 <= index && index < size && index+length < this.size) {
            for (int i = index+length; i < this.size; i++) {
                this.array[i-length] = this.array[i];
            }
            this.size = this.size - length;
        } 
        // throw stuff
    }
    public static void main(String[] args) {
        ArrayListorig testList = new ArrayListorig();
        testList.push_back(0);
        testList.push_back(1);
        testList.push_back(2);
        testList.push_back(3);
        testList.push_back(4);
        testList.push_back(5);
        testList.push_back(6);
        testList.push_back(7);
        testList.push_back(8);
        testList.push_back(9);
        testList.push_back(10);
        testList.push_back(11);
        testList.push_back(12);
        testList.push_back(13);
        testList.reserve(64);
        testList.pop_back();
        testList.get_at(12);
        // testList.get_at(13);
        testList.set_at(12, 24);
        testList.insert(3, 33);
        testList.erase(4, 3);
        System.out.println("Hello World.");
    }
}