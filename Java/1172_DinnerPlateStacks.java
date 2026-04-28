import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

class DinnerPlates {

    public DinnerPlates(int capacity) {
        this.capacity = capacity;
    }
    
    public void push(int val) {
        // Clean invalid indices in nonFullStacks
        while (!nonFullStacks.isEmpty()) {
            int idx = nonFullStacks.iterator().next();
            if (idx >= stacks.size()) {
                nonFullStacks.remove(idx);
                continue;
            }
            List<Integer> stack = stacks.get(idx);
            stack.add(val);
            if (stack.size() == capacity) nonFullStacks.remove(idx);
            return;
        }

        // No existing non-full stack: create a new one
        List<Integer> newStack = new LinkedList<>();
        newStack.add(val);
        stacks.add(newStack);
        int newIdx = stacks.size() - 1;
        if (newStack.size() < capacity) nonFullStacks.add(newIdx);
    }
    
    public int pop() {
        // Trim trailing empty stacks first
        while (!stacks.isEmpty() && stacks.get(stacks.size() - 1).isEmpty()) {
            int last = stacks.size() - 1;
            stacks.remove(last);
            nonFullStacks.remove(last);
        }
        if (stacks.isEmpty()) return -1;

        int index = stacks.size() - 1;
        List<Integer> stack = stacks.get(index);
        int val = stack.remove(stack.size() - 1);
        if (stack.size() == capacity - 1) {
            nonFullStacks.add(index);
        }

        // Trim trailing empties again if pop made last stack empty
        while (!stacks.isEmpty() && stacks.get(stacks.size() - 1).isEmpty()) {
            int last = stacks.size() - 1;
            stacks.remove(last);
            nonFullStacks.remove(last);
        }
        return val;
    }
    
    public int popAtStack(int index) {
        if (index < 0 || index >= stacks.size()) return -1;
        List<Integer> stack = stacks.get(index);
        if (stack.isEmpty()) return -1;
        int val = stack.remove(stack.size() - 1);
        if (stack.size() == capacity - 1) nonFullStacks.add(index);

        // Trim trailing empty stacks (only affects end of list)
        while (!stacks.isEmpty() && stacks.get(stacks.size() - 1).isEmpty()) {
            int last = stacks.size() - 1;
            stacks.remove(last);
            nonFullStacks.remove(last);
        }
        return val;
    }

    private Set<Integer> nonFullStacks = new TreeSet<>(); // to track non-full stacks for push()

    private List<List<Integer>> stacks = new ArrayList<>(); // list of stacks

    private int capacity; // capacity of each stack
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */