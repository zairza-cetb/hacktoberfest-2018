#!/usr/bin/perl
# Based on Cormen third edition
use strict;
use warnings;

sub quicksort (\@) {qsort($_[0], 0, $#{$_[0]})}

sub qsort{
    my ($a, $p, $r) = @_;
    
    if($p < $r){
        my $q = partition($a, $p, $r);
        qsort($a, $p, $q - 1);
        qsort($a, $q + 1, $r);
    }
}

sub partition{
    my ($a, $p, $r) = @_;
    my $x = $a->[$r];
    my $i = $p - 1;
    
    for my $j($p .. $r - 1){
        if($a->[$j] <= $x){
            $i++;
            ($a->[$i], $a->[$j]) = ($a->[$j], $a->[$i]);
        }
    }
    
    ($a->[$i + 1], $a->[$r]) = ($a->[$r], $a->[$i + 1]);
    return $i + 1;
}

my @array = (9, 8, 4, 5, 6, 7, 3, 2, 1);

quicksort @array;
print "@array\n";
