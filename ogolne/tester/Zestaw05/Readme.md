## SORTOWANIA
Zestaw zawiera 5 programów napisanych w języku c++. Programy przedstawiają kilka prostych typów sortowania: insertion sort, bubble sort, counting sort oraz selection sort. Dodatkowo dodano program generator losujący dane wejściowe do sortowania. Programy zawierają flagę "measure mode" przekazywaną jako argument lini komend.
## Skrypty
Zestaw zawiera równiez dwa skrypty.
 Jeden napisany w bashu- **generate_script.sh**, generuje on z pomocą programu Generator dane o roznej wielkości, przekazuje je do programów sortujących a później zapisuje je do odpowiednich plików tekstowych. 
 Drugi napisany w gnuplot- **generate_plot.gp** z danych wygenerowanych przez generate_script.sh tworzy wykres porównujący czas działania programów i zapisuje go jako plik **plot_sortowanie.png**.

 ## Zlozonosc

 przeprowadzilem rowniez eksperyment dla malej liczby danych wejsciowych dla insertion sort. Pesymistyczna zlozonosc tego algorytmu to O(n^2), optymistyczna to O(n). Dla posortowanych rosnąco liczb z zakresu od 1 do 10 liczba iteracji wyniosła 10. dla posortowanych malejąco - 45, a dla liczb w losowej kolejności- 20.
