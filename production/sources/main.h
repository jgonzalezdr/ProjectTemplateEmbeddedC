#ifndef ProjectTemplateEmbeddedC_main_h_
#define ProjectTemplateEmbeddedC_main_h_

#ifdef _UNITTEST_
#define main() production_main()
extern void main();
#endif

#endif // header guard
