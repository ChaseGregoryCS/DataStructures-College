

List::List(){
      iterator = NULL;
      begining = NULL;
      last = NULL;
}

List::List(int id){
      beginning = new Element(id);
      last = begining;
}

~List::List(){
}

Element List::Pop(){
        int n = Length();
        Element rValue = *last;
        
        *last = this[n].DeleteMe();
        
}
