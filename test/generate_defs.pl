use strict;

my $functions = '';
my $suites = '';
my $tests = '';
my $tests_offset = 0;

for my $c (glob 'test_*.c') {

    my $suite_name = substr($c, 5, -2);

    my ($init_func, $clean_func, $setup_func, $teardown_func);
    $init_func = $clean_func = $setup_func = $teardown_func = 'NULL';
    $tests .= "// $suite_name\n";
    my $ntests = 0;

#    my $src;
    open(my $src, $c) or die;
    while (<$src>) {
        if (/^(int (init_${suite_name})\(void\))/) {
            $init_func = $2;
            $functions .= "$1;\n";
        } elsif (/^(int (clean_${suite_name})\(void\))/) {
            $clean_func = $2;
            $functions .= "$1;\n";
        } elsif (/^(int (setup_${suite_name})\(void\))/) {
            $setup_func = $2;
            $functions .= "$1;\n";
        } elsif (/^(int (teardown_${suite_name})\(void\))/) {
            $teardown_func = $2;
            $functions .= "$1;\n";
        } elsif (/^(void test_(\w+)\(void\))/) {
            my $test_name = $2;
            $functions .= "$1;\n";
            $tests .= "{\"$test_name\", test_$test_name},\n";
            ++$ntests;
        }
    } 
    close($src);

    $suites .= "{\"$suite_name\", $init_func, $clean_func," 
                . " $setup_func, $teardown_func, tests + $tests_offset},\n";

    $tests .= "CU_TEST_INFO_NULL,\n";
    $tests_offset += $ntests + 1;

}

#print "funcs=\n$functions\n";
#print "tests=\n$tests\n";
#print "suites=\n$suites\n";
print <<EOT
//== function declarations
$functions

//== tests
CU_TestInfo tests[] = {
$tests
};

//== suites
CU_SuiteInfo suites[] = {
$suites
  CU_SUITE_INFO_NULL,
};
EOT

