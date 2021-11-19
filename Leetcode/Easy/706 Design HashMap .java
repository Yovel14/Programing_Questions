// Time : O(1)
// Space : O(1000001) = O(1) constant time but still a large amount
class MyHashMap {
    private int[] data = new int[1000001];
    
    /** Initialize your data structure here. */
    public MyHashMap() {
        Arrays.fill(data,-1);
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        this.data[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        return this.data[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        this.data[key] = -1;
    }
}