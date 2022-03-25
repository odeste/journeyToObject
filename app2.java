class Buff {
  private int nbBuff;
  private int maxBuff;
  private char tabBuff[];

  public void clearBuff() { //() equiv in lang c (void)
    this.nbBuff = 0; //nbBuff = 0; is also ok
  }
  
  public void initBuff (int maxSize) {
    maxBuff = maxSize; // this.maxBuff = maxSize; is also ok
    tabBuff = new char[maxBuff+1];
    clearBuff();
  }

  public Buff(int maxSize) {
    initBuff(maxSize); // this.initBuff(maxSize); is also ok
  }

  public void addBuff(char c)
  {
    if (nbBuff < maxBuff)
    {
      tabBuff [nbBuff] = c;
      nbBuff += 1;
      tabBuff [nbBuff] = '\0'; //Pas utile en Java, mais utile en C
    }
  }

  public void showBuff()
  {
    for (int i=0; i<nbBuff; i++)
      System.out.print(tabBuff[i]);
  }

  public void processBuff(char specialKey)
  {
    if (nbBuff > 0 && nbBuff < maxBuff && tabBuff[0] == specialKey && tabBuff[nbBuff-1] == specialKey)
      System.out.println("Admin command detected");
    else
      System.out.println(nbBuff + " caracters long entry code detected");
  }
  
}

class Main {
  public static void main(String[] args) {
    
    Buff firstBuff = new Buff  (12);
    Buff secondBuff = new Buff (32);
 
    String s = "Hello, world! How are you today?";
  
    for (int i=0;i < s.length(); i++) 
      {
        firstBuff.addBuff(s.charAt(i));
        secondBuff.addBuff(s.charAt(i));
      }
  
    firstBuff.showBuff();
    System.out.println();

    secondBuff.showBuff();
    System.out.println();
    
    secondBuff.processBuff('#');
    System.out.println();
    
    //main does not return any value, so no return 0;
    }
}
