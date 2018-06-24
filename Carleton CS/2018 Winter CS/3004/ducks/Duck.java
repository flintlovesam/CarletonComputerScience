public abstract class Duck {
FlyBehavior flyBehavior;
QuackBehavior quackBehavior;


public Duck() {}

//allows for all ducks to have display
public abstract void display();


//here we define the two interfaces
//through functions
public void performFly()
{ flyBehavior.fly();
}

public void performQuack()
{ quackBehavior.quack();
}

public void swim() {
System.out.println("All ducks float, even decoys!");
}


public void setFlyBehavior(FlyBehavior fb)
{
  flyBehavior = fb;
}

public void setQuackBehavior(QuackBehavior qb)
{ quackBehavior = qb;
}



}
