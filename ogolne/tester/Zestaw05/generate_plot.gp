set terminal pngcairo enhanced color
set output 'plot_sortowanie.png'
set title 'Porownanie czasow dzialania roznych sortowan'
set xlabel 'Liczba elementow do posortowania'
set ylabel 'Czas sortowania'
set grid

plot 'Bubble_sort_results.txt' with linespoints title 'Bubble Sort', \
     'Counting_sort_results.txt' with linespoints title 'Counting Sort', \
     'Insertion_sort_results.txt' with linespoints title 'Insertion Sort', \
     'Selection_results.txt' with linespoints title 'Selection sort'
