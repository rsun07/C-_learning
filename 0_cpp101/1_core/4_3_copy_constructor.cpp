# i n c l u d e   " 4 _ 2 _ a n d _ 3 _ S t u d e n t . c p p "  
  
 / /   C a l l   c o p y   c o n s t r u c t o r   w h e n   p a s s   v a l u e   i n .   A n d   t h e n   c a l l   d i s t r u c t o r   a f t e r   m e t h o d   e x e c u t i n g .  
 v o i d   s h o w S t u d e n t ( S t u d e n t   s t u d e n t )   {  
 	 s t u d e n t . s h o w ( ) ;  
 	 c o u t   < <   " M e m o r y   a d d r e s s   i n   s h o w S t u d e n t :   "   < <   ( l o n g   l o n g ) & s t u d e n t   < <   e n d l ;  
 }  
  
 S t u d e n t   c r e a t e S t u d e n t ( s t r i n g   n a m e ,   i n t   i d )   {  
 	 S t u d e n t   s t u d e n t ( n a m e ,   i d ) ;  
 	 s t u d e n t . s h o w ( ) ;  
 	 c o u t   < <   " M e m o r y   a d d r e s s   i n   c r e a t e S t u d e n t ( n a m e ,   i d ) :   "   < <   ( l o n g   l o n g ) & s t u d e n t   < <   e n d l ;  
 	 / /   t h i s   i s   r e t u r n   b y   v a l u e .  
 	 / /   t h e o r e t i c a l l y ,   s h o u l d   m a k e   a   c o p y   a n d   r e t u r n ,   b u t   i n   s o m e   c a s e ,   c o m p i l e r   w i l l   o p t i m i z e   t o   m a k e   i t   r e t u r n   b y   r e f e r e n c e  
 	 / /     " R e t u r n   V a l u e   O p t i m i z a t i o n   ( R V O ) "   a n d / o r   " N a m e d   R e t u r n   V a l u e   O p t i m i z a t i o n   ( N R V O ) " .  
 	 r e t u r n   s t u d e n t ;  
 }  
  
 S t u d e n t   c r e a t e S t u d e n t ( )   {  
 	 S t u d e n t   s t u d e n t ;  
 	 s t u d e n t . s h o w ( ) ;  
 	 c o u t   < <   " M e m o r y   a d d r e s s   i n   c r e a t e S t u d e n t ( ) :   "   < <   ( l o n g   l o n g ) & s t u d e n t   < <   e n d l ;  
 	 / /   s a m e   a s   a b o v e  
 	 r e t u r n   s t u d e n t ;  
 }  
  
 i n t   m a i n ( )   {  
  
 	 / /   1 .   m a k e   c o p y   o f   e x i s t   o b j e c t  
 	 S t u d e n t   s t u d e n t ( " J o h n " ,   1 ) ;  
 	 S t u d e n t   s t u d e n t 2 ( s t u d e n t ) ;  
 	 S t u d e n t   s t u d e n t 3   =   s t u d e n t ;  
 	 s t u d e n t 2 . s e t I d ( 2 ) ;  
 	 s t u d e n t 3 . s e t I d ( 3 ) ;  
 	 c o u t   < <   e n d l ;  
 	  
 	 / /   C a l l   n o   a r g   c o n s t r u c t o r ,   n o   c o p y   c o n s t r u c t o r   c a l l  
 	 S t u d e n t   s t u d e n t 4 ;  
 	 / /   o p e r a t o r =   c a l l  
 	 s t u d e n t 4   =   s t u d e n t ;  
 	 s t u d e n t 4 . s e t I d ( 4 ) ;  
  
 	 s t u d e n t . s h o w ( ) ;  
 	 s t u d e n t 2 . s h o w ( ) ;  
 	 s t u d e n t 3 . s h o w ( ) ;  
 	 s t u d e n t 4 . s h o w ( ) ;  
 	 c o u t   < <   e n d l ;  
 	 c o u t   < <   e n d l ;  
  
 	 / /   2 .   P a s s   v a l u e   t o   f u n c t i o n  
 	 c o u t   < <   " M e m o r y   a d d r e s s   i n   m a i n :   "   < <   ( l o n g   l o n g ) & s t u d e n t   < <   e n d l ;  
 	 s h o w S t u d e n t ( s t u d e n t ) ;  
 	 c o u t   < <   e n d l ;  
  
 	 / /   3 .   P a s s   v a l u e   t h r o u g h   f u n c t i o n   r e t u r n  
 	 / /   E x p e c t e d   t o   c a l l   c o p y   c o n s t r u c t o r ,   w h e n   t e s t i n g   o n   m y   M a c ,   r e t u r n   t h e   s a m e   o b j e c t .   I t ' s   b e c a u s e   R V O �r e t u r n   v a l u e   o p t i m i z a t i o n 	�.   T u r n   g + +   R V O   o f f ,   t h e n   w i l l   s e e   c o p y   c o n s t r u c t o r   c a l l e d .  
 	 S t u d e n t   s t u d e n t 5   =   c r e a t e S t u d e n t ( " M a r r y " ,   5 ) ;  
 	 s t u d e n t 5 . s h o w ( ) ;  
 	 c o u t   < <   " M e m o r y   a d d r e s s   i n   m a i n :   "   < <   ( l o n g   l o n g ) & s t u d e n t 5   < <   e n d l ;  
 	 c o u t   < <   e n d l ;  
  
 	 / /   3 .   P a s s   v a l u e   t h r o u g h   f u n c t i o n   r e t u r n  
 	 S t u d e n t   s t u d e n t 6   =   c r e a t e S t u d e n t ( ) ;  
 	 s t u d e n t 6 . s h o w ( ) ;  
 	 c o u t   < <   " M e m o r y   a d d r e s s   i n   m a i n :   "   < <   ( l o n g   l o n g ) & s t u d e n t 6   < <   e n d l ;  
 	 c o u t   < <   e n d l ;  
  
 	 s y s t e m ( " p a u s e " ) ;  
         r e t u r n   0 ;  
 }  
  
 / *  
 S t u d e n t   a l l - a r g   c o n s t r u c t o r   c a l l    
 S t u d e n t   c o p y   c o n s t r u c t o r   c a l l    
 S t u d e n t   c o p y   c o n s t r u c t o r   c a l l    
  
 S t u d e n t   ' n o - a r g ' / ' d e f a u l t '   c o n s t r u c t o r   c a l l    
 C a l l   o p e r a t o r =   o v e r r i d e  
 n a m e   =   J o h n   ,   i d   =   1  
 n a m e   =   J o h n   ,   i d   =   2  
 n a m e   =   J o h n   ,   i d   =   3  
 n a m e   =   J o h n   ,   i d   =   4  
  
  
 M e m o r y   a d d r e s s   i n   m a i n :   1 4 0 7 3 2 7 8 1 9 8 1 4 4 0  
 S t u d e n t   c o p y   c o n s t r u c t o r   c a l l    
 n a m e   =   J o h n   ,   i d   =   1  
 M e m o r y   a d d r e s s   i n   s h o w S t u d e n t :   1 4 0 7 3 2 7 8 1 9 8 1 6 8 0  
 S t u d e n t   d e s t r u c t o r   c a l l    
  
 S t u d e n t   a l l - a r g   c o n s t r u c t o r   c a l l    
 n a m e   =   M a r r y   ,   i d   =   5  
 M e m o r y   a d d r e s s   i n   c r e a t e S t u d e n t ( n a m e ,   i d ) :   1 4 0 7 3 2 7 8 1 9 8 1 6 3 2  
 n a m e   =   M a r r y   ,   i d   =   5  
 M e m o r y   a d d r e s s   i n   m a i n :   1 4 0 7 3 2 7 8 1 9 8 1 6 3 2  
  
 S t u d e n t   ' n o - a r g ' / ' d e f a u l t '   c o n s t r u c t o r   c a l l    
 n a m e   =     ,   i d   =   1  
 M e m o r y   a d d r e s s   i n   c r e a t e S t u d e n t ( ) :   1 4 0 7 3 2 7 8 1 9 8 1 6 8 0  
 n a m e   =     ,   i d   =   1  
 M e m o r y   a d d r e s s   i n   m a i n :   1 4 0 7 3 2 7 8 1 9 8 1 6 8 0  
  
 s h :    
 p a u s e :   n o t   f o u n d  
 S t u d e n t   d e s t r u c t o r   c a l l    
 S t u d e n t   d e s t r u c t o r   c a l l    
 S t u d e n t   d e s t r u c t o r   c a l l    
 S t u d e n t   d e s t r u c t o r   c a l l    
 S t u d e n t   d e s t r u c t o r   c a l l    
 S t u d e n t   d e s t r u c t o r   c a l l    
  
  
 * *   P r o c e s s   e x i t e d   -   R e t u r n   C o d e :   0   * *  
 * / 