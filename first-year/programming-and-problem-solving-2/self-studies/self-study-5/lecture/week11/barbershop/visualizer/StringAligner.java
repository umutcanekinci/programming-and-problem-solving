package week11.barbershop.visualizer;

public class StringAligner {
    public StringAligner() {
    }

    public String indented(String text, int leftSpace, int rightSpace) {
        String st = String.format("%" + leftSpace + "s%s%" + rightSpace + "s", "", text, "");
        return st.toString();
    }

    public String indented(String text, int leftSpace) {
        String st = String.format("%" + leftSpace + "s%s", "", text);
        return st.toString();
    }

    public String rAligned(String text, int width) {
        if (width == 0)
            return "";
        String st = String.format("%" + width + "s", text);
        return st.toString();
    }

    public String lAligned(String text, int width) {
        if (width == 0)
            return "";
        String st = String.format("%-" + width + "s", text);
        return st.toString();
    }

    public String centralized(String text, int width) {
        int spaceCount = (width - text.length()) / 2;
        String st = String.format("%" + spaceCount + "s%s%" + spaceCount + "s", "", text, "");
        return st.toString();
    }
}