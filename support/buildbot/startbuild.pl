#!/usr/bin/perl

use File::Basename;

my ($myself, $path) = fileparse($0);
chdir($path);

require 'helpers.pm';

chdir('../../installer/builder');

my $output;
if ($^O eq "linux") {
	$output = `mono builder.exe directions.info`;
} else {
	$output = `builder.exe directions.info`;
}
print $output . "\n";

if ($output =~ /Build failed/) {
	die "Build failed!\n";
} else {
	exit(0);
}

