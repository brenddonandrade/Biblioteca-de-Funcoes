reset 
set terminal pdfcairo
set output "grafico-1.pdf"
set xzeroaxis
plot [0:5] ((x*exp((-x)/3.0)) - 1)
set output
set terminal qt