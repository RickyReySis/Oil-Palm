void fuzzyset(){

//Inisialisasi Fuzzy Input

// Fuzzy Input 1 - Kelembaban Tanah
  FuzzyInput *kelembabanTanah = new FuzzyInput(1);
  kelembabanTanah->addFuzzySet(kering);
  kelembabanTanah->addFuzzySet(normal); 
  kelembabanTanah->addFuzzySet(basah);
  fuzzy->addFuzzyInput(kelembabanTanah);

  // Fuzzy Input 2 - Suhu
  FuzzyInput *suhu = new FuzzyInput(2);
  suhu->addFuzzySet(dingin);
  suhu->addFuzzySet(hangat);
  suhu->addFuzzySet(panas);
  fuzzy->addFuzzyInput(suhu);

  // Fuzzy Input 3 - Kelembaban
  FuzzyInput *kelembaban = new FuzzyInput(3);
  kelembaban->addFuzzySet(tidaklembap);
  kelembaban->addFuzzySet(lembapsedang);
  kelembaban->addFuzzySet(lembap);
  fuzzy->addFuzzyInput(kelembaban);
   
  // Fuzzy Output - Status Motor
  FuzzyOutput *statusMotor = new FuzzyOutput(1);
  statusMotor->addFuzzySet(on);
  statusMotor->addFuzzySet(off);
  fuzzy->addFuzzyOutput(statusMotor);

}
