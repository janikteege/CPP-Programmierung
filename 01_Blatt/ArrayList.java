public class ArrayList
{
    private static final int BASE_CAPACITY = 32;
    
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
    public ArrayList()
    {
        this.array = new int[BASE_CAPACITY];
        this.capacity = BASE_CAPACITY;
        this.size = 0;
    }

    // Increase the capacity to hold at least newSize elements.
    // This method never decreases the size of the ArrayList!
    public void reserve(int newSize)
    {
        if (newSize > capacity) {
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
            capacity = newSize;
        }
    }

    // Add an element to the back of the ArrayList.
    public void push_back(int element)
    {
        if (size >= capacity) {
            reserve((capacity * 3) / 2 + 1);
        }
        array[size] = element;
        size++;
    }

    // Remove the last element from the ArrayList.
    public void pop_back()
    {
        if (size > 0) {
            size--;
        }
    }

    // Return the value at the given position.
    public int get_at(int index)
    {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return array[index];
    }

    // Set the value at the given position.
    public void set_at(int index, int element)
    {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        array[index] = element;
    }

    // Insert the element at the given index. 
    // The elements after that position are shifted towards the back.
    public void insert(int index, int element)
    {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        if (size >= capacity) {
            reserve((capacity * 3) / 2 + 1);
        }
        // shift elements from back 1 by 1
        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = element;
        size++;
    }

    // Erase a block of elements of size length, starting at index.
    // The elements following this block are shifted towards the front.
    public void erase(int index, int length)
    {
        if (index < 0 || index + length > size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        // just overwrite with elements after the block
        for (int i = index; i + length < size; i++) {
            array[i] = array[i + length];
        }
        size -= length;
    }
}
