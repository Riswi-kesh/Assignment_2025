Flat Assignment No. 31 – Morphological Analyzer (English)

## Description ##
This project implements a **basic morphological analyzer for English words** using **C++ and the OpenFst library**.  

The program takes an **English word as input**, analyzes it, and outputs its **root word + part of speech (POS) + grammatical feature**.  
It also constructs and saves an **FST (Finite-State Transducer)** representation of the input word.  

This is a **rule-based morphological analyzer**, focusing on common English suffixes like **`-ing`, `-ed`, `-er`, `-est`, `-ly`**.


Examples for Morphological Analyzer (English)
---------------------------------------------

1. Input: running, 
     Output: run + V + GER
   (GER = Gerund, verb ending in -ing used as a noun or continuous form)

2. Input: played, 
     Output: play + V + PAST
   (PAST = Verb in past tense)

3. Input: biggest,
     Output: big + ADJ + SUPER
   (SUPER = Superlative adjective, e.g., biggest, tallest)

4. Input: quickly,
     Output: quick + ADV
   (ADV = Adverb, modifies verbs, adjectives, or other adverbs)
  
