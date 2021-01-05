import React from 'react';

const Square = ({ value, onClick }) => (
  <button type="button" className="square" onClick={onClick}>
    {value}
  </button>
);

export default Square;
