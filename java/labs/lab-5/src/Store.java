import java.util.ArrayList;
import java.util.List;

public class Store {
    List<Product> products = new ArrayList<>();

    public void add(Product product) {
        if(product == null)
            throw new IllegalArgumentException("Product cannot be null.");

        products.add(product);
    }

    public void remove(Product product) {
        if(product == null)
            throw new IllegalArgumentException("Product cannot be null.");

        if(!products.contains(product))
            System.out.print("The product " + product.getName() + " is not exists in store.");

        products.remove(product);
    }

    public List<Product> searchByName(String name) {
        if(name == null)
            throw new IllegalArgumentException("Name cannot be null.");

        List<Product> result = new ArrayList<>();
        for(Product product : products) {
            if(product.getName().equals(name))
                result.add(product);
        }
        return result;
    }

    public double getTotalValue() {
        return products.stream().mapToDouble(p -> p.getPrice() + p.getTax()).sum();
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("Products \n");
        products.forEach(sb::append);
        return sb.toString();
    }

}