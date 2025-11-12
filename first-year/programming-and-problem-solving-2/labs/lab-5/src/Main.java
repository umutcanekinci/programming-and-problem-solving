public class Main {

    public static void main(String[] args) {
        Store store = new Store();
        Product[] products = new Product[] {
            new ElectronicProduct(0, "EP1", 100, "Desc", "Manuf", "Model", 3),
            new ElectronicProduct(1, "EP2", 200, "Desc", "Manuf", "Model", 3),
            new BookProduct(2, "BP1", 300, "Desc", "Auth", "Genre", 100),
            new BookProduct(3, "BP2", 400, "Desc", "Auth", "Genre", 200)
        };
    
        for(Product product : products) {
            store.add(product);
        }

        System.out.println(store);
    }

}
