void fuzzyrule(){

// Aturan 1 
  FuzzyRuleAntecedent *dingin_kering_1 = new FuzzyRuleAntecedent();
  dingin_kering_1->joinWithAND(dingin, kering);
  FuzzyRuleAntecedent *tidaklembap_1 = new FuzzyRuleAntecedent();
  tidaklembap_1->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_dingin_kering_tidaklembap_1 = new FuzzyRuleAntecedent();
  if_dingin_kering_tidaklembap_1->joinWithAND(dingin_kering_1, tidaklembap_1);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_1 = new FuzzyRuleConsequent();
  then_on_1->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule01 = new FuzzyRule(1, if_dingin_kering_tidaklembap_1, then_on_1);
  //Memasukan Fuzzy Rule 1 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule01);

// Aturan 2 
  FuzzyRuleAntecedent *hangat_kering_2 = new FuzzyRuleAntecedent();
  hangat_kering_2->joinWithAND(hangat, kering);
  FuzzyRuleAntecedent *tidaklembap_2 = new FuzzyRuleAntecedent();
  tidaklembap_2->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_hangat_kering_tidaklembap_2 = new FuzzyRuleAntecedent();
  if_hangat_kering_tidaklembap_2->joinWithAND(hangat_kering_2, tidaklembap_2);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_2 = new FuzzyRuleConsequent();
  then_on_2->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule02 = new FuzzyRule(2, if_hangat_kering_tidaklembap_2, then_on_2);
  //Memasukan Fuzzy Rule 2 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule02);

// Aturan 3
  FuzzyRuleAntecedent *panas_kering_3 = new FuzzyRuleAntecedent();
  panas_kering_3->joinWithAND(panas, kering);
  FuzzyRuleAntecedent *tidaklembap_3 = new FuzzyRuleAntecedent();
  tidaklembap_3->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_panas_kering_tidaklembap_3 = new FuzzyRuleAntecedent();
  if_panas_kering_tidaklembap_3->joinWithAND(panas_kering_3, tidaklembap_3);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_3 = new FuzzyRuleConsequent();
  then_on_3->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule03 = new FuzzyRule(3, if_panas_kering_tidaklembap_3, then_on_3);
  //Memasukan Fuzzy Rule 3 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule03);

// Aturan 4 
  FuzzyRuleAntecedent *dingin_kering_4 = new FuzzyRuleAntecedent();
  dingin_kering_4->joinWithAND(dingin, kering);
  FuzzyRuleAntecedent *lembapsedang_4 = new FuzzyRuleAntecedent();
  lembapsedang_4->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_dingin_kering_lembapsedang_4 = new FuzzyRuleAntecedent();
  if_dingin_kering_lembapsedang_4->joinWithAND(dingin_kering_4, lembapsedang_4);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_4 = new FuzzyRuleConsequent();
  then_on_4->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule04 = new FuzzyRule(4, if_dingin_kering_lembapsedang_4, then_on_4);
  //Memasukan Fuzzy Rule 4 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule04);

// Aturan 5 
  FuzzyRuleAntecedent *hangat_kering_5 = new FuzzyRuleAntecedent();
  hangat_kering_5->joinWithAND(hangat, kering);
  FuzzyRuleAntecedent *lembapsedang_5 = new FuzzyRuleAntecedent();
  lembapsedang_5->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_hangat_kering_lembapsedang_5 = new FuzzyRuleAntecedent();
  if_hangat_kering_lembapsedang_5->joinWithAND(hangat_kering_5, lembapsedang_5);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_5 = new FuzzyRuleConsequent();
  then_on_5->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule05 = new FuzzyRule(5, if_hangat_kering_lembapsedang_5, then_on_5);
  //Memasukan Fuzzy Rule 5 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule05);

// Aturan 6
  FuzzyRuleAntecedent *panas_kering_6 = new FuzzyRuleAntecedent();
  panas_kering_6->joinWithAND(panas, kering);
  FuzzyRuleAntecedent *lembapsedang_6 = new FuzzyRuleAntecedent();
  lembapsedang_6->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_panas_kering_lembapsedang_6 = new FuzzyRuleAntecedent();
  if_panas_kering_lembapsedang_6->joinWithAND(panas_kering_6, lembapsedang_6);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_6 = new FuzzyRuleConsequent();
  then_on_6->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule06 = new FuzzyRule(1, if_panas_kering_lembapsedang_6, then_on_6);
  //Memasukan Fuzzy Rule 6 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule06);

// Aturan 7 
  FuzzyRuleAntecedent *dingin_kering_7 = new FuzzyRuleAntecedent();
  dingin_kering_7->joinWithAND(dingin, kering);
  FuzzyRuleAntecedent *lembap_7 = new FuzzyRuleAntecedent();
  lembap_7->joinSingle(lembap);
  FuzzyRuleAntecedent *if_dingin_kering_lembap_7 = new FuzzyRuleAntecedent();
  if_dingin_kering_lembap_7->joinWithAND(dingin_kering_7, lembap_7);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_7 = new FuzzyRuleConsequent();
  then_on_7->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule07 = new FuzzyRule(7, if_dingin_kering_lembap_7, then_on_7);
  //Memasukan Fuzzy Rule 7 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule07);

// Aturan 8 
  FuzzyRuleAntecedent *hangat_kering_8 = new FuzzyRuleAntecedent();
  hangat_kering_8->joinWithAND(hangat, kering);
  FuzzyRuleAntecedent *lembap_8 = new FuzzyRuleAntecedent();
  lembap_8->joinSingle(lembap);
  FuzzyRuleAntecedent *if_hangat_kering_lembap_8 = new FuzzyRuleAntecedent();
  if_hangat_kering_lembap_8->joinWithAND(hangat_kering_8, lembap_8);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_8 = new FuzzyRuleConsequent();
  then_on_8->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule08 = new FuzzyRule(8, if_hangat_kering_lembap_8, then_on_8);
  //Memasukan Fuzzy Rule 8 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule08);

// Aturan 9
  FuzzyRuleAntecedent *panas_kering_9 = new FuzzyRuleAntecedent();
  panas_kering_9->joinWithAND(panas, kering);
  FuzzyRuleAntecedent *lembap_9 = new FuzzyRuleAntecedent();
  lembap_9->joinSingle(lembap);
  FuzzyRuleAntecedent *if_panas_kering_lembap_9 = new FuzzyRuleAntecedent();
  if_panas_kering_lembap_9->joinWithAND(panas_kering_9, lembap_9);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_9 = new FuzzyRuleConsequent();
  then_on_9->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule09 = new FuzzyRule(9, if_panas_kering_lembap_9, then_on_9);
  //Memasukan Fuzzy Rule 9 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule09);

// Aturan 10 
  FuzzyRuleAntecedent *dingin_normal_10 = new FuzzyRuleAntecedent();
  dingin_normal_10->joinWithAND(dingin, normal);
  FuzzyRuleAntecedent *tidaklembap_10 = new FuzzyRuleAntecedent();
  tidaklembap_10->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_dingin_normal_tidaklembap_10 = new FuzzyRuleAntecedent();
  if_dingin_normal_tidaklembap_10->joinWithAND(dingin_normal_10, tidaklembap_10);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_10 = new FuzzyRuleConsequent();
  then_off_10->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule010 = new FuzzyRule(10, if_dingin_normal_tidaklembap_10, then_off_10);
  //Memasukan Fuzzy Rule 10 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule010);

// Aturan 11 
  FuzzyRuleAntecedent *hangat_normal_11 = new FuzzyRuleAntecedent();
  hangat_normal_11->joinWithAND(hangat, normal);
  FuzzyRuleAntecedent *tidaklembap_11 = new FuzzyRuleAntecedent();
  tidaklembap_11->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_hangat_normal_tidaklembap_11 = new FuzzyRuleAntecedent();
  if_hangat_normal_tidaklembap_11->joinWithAND(hangat_normal_11, tidaklembap_11);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_11 = new FuzzyRuleConsequent();
  then_off_11->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule011 = new FuzzyRule(11, if_hangat_normal_tidaklembap_11, then_off_11);
  //Memasukan Fuzzy Rule 11 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule011);

// Aturan 12
  FuzzyRuleAntecedent *panas_normal_12 = new FuzzyRuleAntecedent();
  panas_normal_12->joinWithAND(panas, normal);
  FuzzyRuleAntecedent *tidaklembap_12 = new FuzzyRuleAntecedent();
  tidaklembap_12->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_panas_normal_tidaklembap_12 = new FuzzyRuleAntecedent();
  if_panas_normal_tidaklembap_12->joinWithAND(panas_normal_12, tidaklembap_12);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_12 = new FuzzyRuleConsequent();
  then_on_12->addOutput(on);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule012 = new FuzzyRule(12, if_panas_normal_tidaklembap_12, then_on_12);
  //Memasukan Fuzzy Rule 12 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule012);

// Aturan 13 
  FuzzyRuleAntecedent *dingin_normal_13 = new FuzzyRuleAntecedent();
  dingin_normal_13->joinWithAND(dingin, normal);
  FuzzyRuleAntecedent *lembapsedang_13 = new FuzzyRuleAntecedent();
  lembapsedang_13->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_dingin_normal_lembapsedang_13 = new FuzzyRuleAntecedent();
  if_dingin_normal_lembapsedang_13->joinWithAND(dingin_normal_13, lembapsedang_13);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_13 = new FuzzyRuleConsequent();
  then_off_13->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule013 = new FuzzyRule(13, if_dingin_normal_lembapsedang_13, then_off_13);
  //Memasukan Fuzzy Rule 13 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule013);

// Aturan 14 
  FuzzyRuleAntecedent *hangat_normal_14 = new FuzzyRuleAntecedent();
  hangat_normal_14->joinWithAND(hangat, normal);
  FuzzyRuleAntecedent *lembapsedang_14 = new FuzzyRuleAntecedent();
  lembapsedang_14->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_hangat_normal_lembapsedang_14 = new FuzzyRuleAntecedent();
  if_hangat_normal_lembapsedang_14->joinWithAND(hangat_normal_14, lembapsedang_14);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_14 = new FuzzyRuleConsequent();
  then_off_14->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule014 = new FuzzyRule(14, if_hangat_normal_lembapsedang_14, then_off_14);
  //Memasukan Fuzzy Rule 14 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule014);

// Aturan 15
  FuzzyRuleAntecedent *panas_normal_15 = new FuzzyRuleAntecedent();
  panas_normal_15->joinWithAND(panas, normal);
  FuzzyRuleAntecedent *lembapsedang_15 = new FuzzyRuleAntecedent();
  lembapsedang_15->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_panas_normal_lembapsedang_15 = new FuzzyRuleAntecedent();
  if_panas_normal_lembapsedang_15->joinWithAND(panas_normal_15, lembapsedang_15);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_15 = new FuzzyRuleConsequent();
  then_off_15->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule015 = new FuzzyRule(15, if_panas_normal_lembapsedang_15, then_off_15);
  //Memasukan Fuzzy Rule 15 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule015);

// Aturan 16 
  FuzzyRuleAntecedent *dingin_normal_16 = new FuzzyRuleAntecedent();
  dingin_normal_16->joinWithAND(dingin, normal);
  FuzzyRuleAntecedent *lembap_16 = new FuzzyRuleAntecedent();
  lembap_16->joinSingle(lembap);
  FuzzyRuleAntecedent *if_dingin_normal_lembap_16 = new FuzzyRuleAntecedent();
  if_dingin_normal_lembap_16->joinWithAND(dingin_normal_16, lembap_16);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_16 = new FuzzyRuleConsequent();
  then_off_16->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule016 = new FuzzyRule(16, if_dingin_normal_lembap_16, then_off_16);
  //Memasukan Fuzzy Rule 16 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule016);

// Aturan 17 
  FuzzyRuleAntecedent *hangat_normal_17 = new FuzzyRuleAntecedent();
  hangat_normal_17->joinWithAND(hangat, normal);
  FuzzyRuleAntecedent *lembap_17 = new FuzzyRuleAntecedent();
  lembap_17->joinSingle(lembap);
  FuzzyRuleAntecedent *if_hangat_normal_lembap_17 = new FuzzyRuleAntecedent();
  if_hangat_normal_lembap_17->joinWithAND(hangat_normal_17, lembap_17);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_17 = new FuzzyRuleConsequent();
  then_off_17->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule017 = new FuzzyRule(17, if_hangat_normal_lembap_17, then_off_17);
  //Memasukan Fuzzy Rule 17 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule017);

// Aturan 18
  FuzzyRuleAntecedent *panas_normal_18 = new FuzzyRuleAntecedent();
  panas_normal_18->joinWithAND(panas, normal);
  FuzzyRuleAntecedent *lembap_18 = new FuzzyRuleAntecedent();
  lembap_18->joinSingle(lembap);
  FuzzyRuleAntecedent *if_panas_normal_lembap_18 = new FuzzyRuleAntecedent();
  if_panas_normal_lembap_18->joinWithAND(panas_normal_18, lembap_18);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_off_18 = new FuzzyRuleConsequent();
  then_off_18->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule018 = new FuzzyRule(18, if_panas_normal_lembap_18, then_off_18);
  //Memasukan Fuzzy Rule 18 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule018);

  // Aturan 19 
  FuzzyRuleAntecedent *dingin_basah_19 = new FuzzyRuleAntecedent();
  dingin_basah_19->joinWithAND(dingin, basah);
  FuzzyRuleAntecedent *tidaklembap_19 = new FuzzyRuleAntecedent();
  tidaklembap_19->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_dingin_basah_tidaklembap_19 = new FuzzyRuleAntecedent();
  if_dingin_basah_tidaklembap_19->joinWithAND(dingin_basah_19, tidaklembap_19);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_19 = new FuzzyRuleConsequent();
  then_on_19->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule019 = new FuzzyRule(19, if_dingin_basah_tidaklembap_19, then_on_19);
  //Memasukan Fuzzy Rule 19 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule019);

// Aturan 20 
  FuzzyRuleAntecedent *hangat_basah_20 = new FuzzyRuleAntecedent();
  hangat_basah_20->joinWithAND(hangat, basah);
  FuzzyRuleAntecedent *tidaklembap_20 = new FuzzyRuleAntecedent();
  tidaklembap_20->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_hangat_basah_tidaklembap_20 = new FuzzyRuleAntecedent();
  if_hangat_basah_tidaklembap_20->joinWithAND(hangat_basah_20, tidaklembap_20);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_20 = new FuzzyRuleConsequent();
  then_on_20->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule020 = new FuzzyRule(20, if_hangat_basah_tidaklembap_20, then_on_20);
  //Memasukan Fuzzy Rule 20 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule020);

// Aturan 21
  FuzzyRuleAntecedent *panas_basah_21 = new FuzzyRuleAntecedent();
  panas_basah_21->joinWithAND(panas, basah);
  FuzzyRuleAntecedent *tidaklembap_21 = new FuzzyRuleAntecedent();
  tidaklembap_21->joinSingle(tidaklembap);
  FuzzyRuleAntecedent *if_panas_basah_tidaklembap_21 = new FuzzyRuleAntecedent();
  if_panas_basah_tidaklembap_21->joinWithAND(panas_basah_21, tidaklembap_21);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_21 = new FuzzyRuleConsequent();
  then_on_21->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule021 = new FuzzyRule(21, if_panas_basah_tidaklembap_21, then_on_21);
  //Memasukan Fuzzy Rule 21 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule021);

// Aturan 22 
  FuzzyRuleAntecedent *dingin_basah_22 = new FuzzyRuleAntecedent();
  dingin_basah_22->joinWithAND(dingin, basah);
  FuzzyRuleAntecedent *lembapsedang_22 = new FuzzyRuleAntecedent();
  lembapsedang_22->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_dingin_basah_lembapsedang_22 = new FuzzyRuleAntecedent();
  if_dingin_basah_lembapsedang_22->joinWithAND(dingin_basah_22, lembapsedang_22);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_22 = new FuzzyRuleConsequent();
  then_on_22->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule022 = new FuzzyRule(22, if_dingin_basah_lembapsedang_22, then_on_22);
  //Memasukan Fuzzy Rule 22 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule022);

// Aturan 23 
  FuzzyRuleAntecedent *hangat_basah_23 = new FuzzyRuleAntecedent();
  hangat_basah_23->joinWithAND(hangat, basah);
  FuzzyRuleAntecedent *lembapsedang_23 = new FuzzyRuleAntecedent();
  lembapsedang_23->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_hangat_basah_lembapsedang_23 = new FuzzyRuleAntecedent();
  if_hangat_basah_lembapsedang_23->joinWithAND(hangat_basah_23, lembapsedang_23);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_23 = new FuzzyRuleConsequent();
  then_on_23->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule023 = new FuzzyRule(23, if_hangat_basah_lembapsedang_23, then_on_23);
  //Memasukan Fuzzy Rule 23 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule023);

// Aturan 24
  FuzzyRuleAntecedent *panas_basah_24 = new FuzzyRuleAntecedent();
  panas_basah_24->joinWithAND(panas, basah);
  FuzzyRuleAntecedent *lembapsedang_24 = new FuzzyRuleAntecedent();
  lembapsedang_24->joinSingle(lembapsedang);
  FuzzyRuleAntecedent *if_panas_basah_lembapsedang_24 = new FuzzyRuleAntecedent();
  if_panas_basah_lembapsedang_24->joinWithAND(panas_basah_24, lembapsedang_24);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_24 = new FuzzyRuleConsequent();
  then_on_24->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule024 = new FuzzyRule(24, if_panas_basah_lembapsedang_24, then_on_24);
  //Memasukan Fuzzy Rule 24 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule024);

// Aturan 25 
  FuzzyRuleAntecedent *dingin_basah_25 = new FuzzyRuleAntecedent();
  dingin_basah_25->joinWithAND(dingin, basah);
  FuzzyRuleAntecedent *lembap_25 = new FuzzyRuleAntecedent();
  lembap_25->joinSingle(lembap);
  FuzzyRuleAntecedent *if_dingin_basah_lembap_25 = new FuzzyRuleAntecedent();
  if_dingin_basah_lembap_25->joinWithAND(dingin_basah_25, lembap_25);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_25 = new FuzzyRuleConsequent();
  then_on_25->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule025 = new FuzzyRule(25, if_dingin_basah_lembap_25, then_on_25);
  //Memasukan Fuzzy Rule 25 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule025);

// Aturan 26 
  FuzzyRuleAntecedent *hangat_basah_26 = new FuzzyRuleAntecedent();
  hangat_basah_26->joinWithAND(hangat, basah);
  FuzzyRuleAntecedent *lembap_26 = new FuzzyRuleAntecedent();
  lembap_26->joinSingle(lembap);
  FuzzyRuleAntecedent *if_hangat_basah_lembap_26 = new FuzzyRuleAntecedent();
  if_hangat_basah_lembap_26->joinWithAND(hangat_basah_26, lembap_26);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_26 = new FuzzyRuleConsequent();
  then_on_26->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule026 = new FuzzyRule(26, if_hangat_basah_lembap_26, then_on_26);
  //Memasukan Fuzzy Rule 26 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule026);

// Aturan 27
  FuzzyRuleAntecedent *panas_basah_27 = new FuzzyRuleAntecedent();
  panas_basah_27->joinWithAND(panas, basah);
  FuzzyRuleAntecedent *lembap_27 = new FuzzyRuleAntecedent();
  lembap_27->joinSingle(lembap);
  FuzzyRuleAntecedent *if_panas_basah_lembap_27 = new FuzzyRuleAntecedent();
  if_panas_basah_lembap_27->joinWithAND(panas_basah_27, lembap_27);

  //Inisialisasai Fuzzy RuleConsequent(Output Fuzzy)
  FuzzyRuleConsequent *then_on_27 = new FuzzyRuleConsequent();
  then_on_27->addOutput(off);  

  //Inisialisasi Fuzzy Rule
  FuzzyRule *fuzzyRule027 = new FuzzyRule(27, if_panas_basah_lembap_27, then_on_27);
  //Memasukan Fuzzy Rule 27 ke Dalam Logika Fuzzy
  fuzzy->addFuzzyRule(fuzzyRule027);

}
