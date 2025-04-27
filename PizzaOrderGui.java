import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PizzaOrderGui extends JFrame{
    private int totalorder;
    private JLabel t_order;
    private int total_price;
    private JLabel t_price;

    private JButton Combo;
    private JLabel Combo_label;
    public int combo_price = 15000;
    private JLabel c_order_Label;
    private int combo_order;

    private JButton Potato;
    private JLabel Potato_label;
    public int potato_price = 12000;
    private JLabel p_order_Label;
    private int potato_order;

    private JButton Bulgogi;
    private JLabel Bulgogi_label;
    public int bulgogi_price = 16000;
    private JLabel b_order_Label;
    private int bulgogi_order;

    private JButton Reset;

    public PizzaOrderGui(){
        totalorder=0;
        total_price=0;
        combo_order=0;
        potato_order=0;
        bulgogi_order=0;

        setSize(600,400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("Pizza restaurant order board");
        setLayout(new GridLayout(4,1));

        JPanel comboPannel = new JPanel();
        comboPannel.setLayout(new BoxLayout(comboPannel, BoxLayout.Y_AXIS));
        Combo = new JButton("Combo Pizza");
        Combo_label = new JLabel("Price:15,000Won");
        c_order_Label = new JLabel("Order:"+combo_order);
        comboPannel.add(Combo);
        comboPannel.add(Combo_label);
        comboPannel.add(c_order_Label);

        JPanel potatoPannel = new JPanel();
        potatoPannel.setLayout(new BoxLayout(potatoPannel, BoxLayout.Y_AXIS));
        Potato = new JButton("Potato Pizza");
        Potato_label = new JLabel("Price:12,000won");
        p_order_Label = new JLabel("Order:"+potato_order);
        potatoPannel.add(Potato);
        potatoPannel.add(Potato_label);
        potatoPannel.add(p_order_Label);

        JPanel bulgogiPannel = new JPanel();
        bulgogiPannel.setLayout(new BoxLayout(bulgogiPannel, BoxLayout.Y_AXIS));
        Bulgogi = new JButton("Bulgogi Pizza");
        Bulgogi_label = new JLabel("Price:16,000won");
        b_order_Label = new JLabel("Order:"+bulgogi_order);
        bulgogiPannel.add(Bulgogi);
        bulgogiPannel.add(Bulgogi_label);
        bulgogiPannel.add(b_order_Label);

        JPanel Info_Panel = new JPanel();
        Info_Panel.setLayout(new FlowLayout());
        t_order = new JLabel("Total Orders:"+totalorder+" ");
        t_price = new JLabel("Total Price:"+total_price+" won");

        Info_Panel.add(t_order);
        Info_Panel.add(t_price);

        JPanel resetPannel = new JPanel();
        Reset = new JButton("Resetting Orders");
        resetPannel.add(Reset);

        JPanel TopPannel = new JPanel();
        TopPannel.setLayout(new FlowLayout(FlowLayout.CENTER,50,5));
        TopPannel.add(comboPannel);
        TopPannel.add(potatoPannel);
        TopPannel.add(bulgogiPannel);

        JPanel EmptyPannel = new JPanel();

        add(TopPannel);
        add(EmptyPannel);
        add(Info_Panel);
        add(resetPannel);

        combo_listners();
        potato_listners();
        bulgogi_listners();
        reset_listners();

        setVisible(true);

    }

    private void updateOrder(int pizzaType, int price){
        totalorder++;
        total_price += price;

        if(pizzaType==1){
            combo_order++;
            c_order_Label.setText("Order:"+combo_order);
        } else if (pizzaType==2) {
            potato_order++;
            p_order_Label.setText("Order:"+potato_order);
        } else if (pizzaType==3) {
            bulgogi_order++;
            b_order_Label.setText("Order:"+bulgogi_order);
        }
        t_order.setText("Total Orders:"+totalorder+" ");
        t_price.setText("Total Price:"+total_price+" won");
    }

    private void resetOrder(){
        totalorder = 0;
        total_price = 0;
        combo_order = 0;
        potato_order = 0;
        bulgogi_order = 0;
        c_order_Label.setText("Order:"+combo_order);
        p_order_Label.setText("Order:"+potato_order);
        b_order_Label.setText("Order:"+bulgogi_order);
        t_order.setText("Total Orders:"+totalorder+" ");
        t_price.setText("Total Price:"+total_price+" won");
    }

    private void combo_listners(){
        Combo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                updateOrder(1,combo_price);
            }
        });
    }

    private void potato_listners(){
        Potato.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                updateOrder(2,potato_price);
            }
        });
    }

    private void bulgogi_listners(){
        Bulgogi.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                updateOrder(3,bulgogi_price);
            }
        });
    }

    private void reset_listners(){
        Reset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                resetOrder();
            }
        });
    }
}
