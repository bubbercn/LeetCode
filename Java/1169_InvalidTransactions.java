import java.util.ArrayList;
import java.util.List;

class Transaction {
    String name;
    int time;
    int amount;
    String city;
    String original;

    public Transaction(String name, int time, int amount, String city, String original) {
        this.name = name;
        this.time = time;
        this.amount = amount;
        this.city = city;
        this.original = original;
    }
}

class Solution1169 {
    public List<String> invalidTransactions(String[] transactions) {
        List<String> result = new ArrayList<>();
        List<Transaction> transactionList = new ArrayList<>();
        for (String transaction : transactions) {
            String[] parts = transaction.split(",");
            String name = parts[0];
            int time = Integer.parseInt(parts[1]);
            int amount = Integer.parseInt(parts[2]);
            String city = parts[3];
            Transaction transactionObj = new Transaction(name, time, amount, city, transaction);
            transactionList.add(transactionObj);
        }
        for (int i = 0; i < transactionList.size(); i++) {
            Transaction t1 = transactionList.get(i);
            if (t1.amount > 1000) {
                result.add(t1.original);
                continue;
            }
            for (int j = 0; j < transactionList.size(); j++) {
                if (j == i) 
                    continue;
                Transaction t2 = transactionList.get(j);
                if (t1.name.equals(t2.name) && Math.abs(t1.time - t2.time) <= 60 && !t1.city.equals(t2.city)) {
                    result.add(t1.original);
                }
            }
        }
        return result;
    }
}